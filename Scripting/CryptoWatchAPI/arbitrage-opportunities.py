import requests
import json
import time

# define constants
EXECUTION_INTERVAL_SECONDS = 60.0
CRYPTOWATCH_BASE_URL = "https://api.cryptowat.ch/{}"


def get_wait_time(t0):
    return EXECUTION_INTERVAL_SECONDS - ((time.time() - t0) % EXECUTION_INTERVAL_SECONDS)


def get_order_book_for_market(market):
    exchange_pair_req = requests.get(market['route'])
    if exchange_pair_req.status_code == 200:
        exchange_pair_json = json.loads(exchange_pair_req.content)
        order_book_url = exchange_pair_json['result']['routes']['orderbook']
        order_book_req = requests.get(order_book_url)
        if order_book_req.status_code == 200:
            order_book_json = json.loads(order_book_req.content)
            if 'result' not in order_book_json:
                print(order_book_url)
                return {'error': "OrderBook contains no results."}
            if 'asks' not in order_book_json['result'] or 'bids' not in order_book_json['result']:
                return {'error': "OrderBook contains no asks/bids."}
            if len(order_book_json['result']['asks']) == 0 or len(order_book_json['result']['bids']) == 0:
                return {'error': "OrderBook contains empty lists of asks/bids."}
            return {
                'askPrice': float(order_book_json['result']['asks'][0][0]),
                'askLiquidity': float(order_book_json['result']['asks'][0][1]),
                'bidPrice': float(order_book_json['result']['bids'][0][0]),
                'bidLiquidity': float(order_book_json['result']['bids'][0][1]),
                'pair': market['pair'],
                'exchange': market['exchange'],
                'active': market['active']
            }
        else:
            return {
                'code': order_book_req,
                'url': order_book_url,
                'error': "OrderBook request was not successful."
            }
    else:
        return {
            'code': exchange_pair_req.status_code,
            'url': market['route'],
            'error': "ExchangePair request was not successful."
        }


def compare_order_books(book1, book2):
    if 'error' in book1 or 'error' in book2:
        return {'diff': -1}
    diff = book1['bidPrice'] - book2['askPrice']
    result = {
        'book1': book1,
        'book2': book2,
        'diff': diff
    }
    if diff > 0:
        print(json.dumps(result, indent=2))


def compare_crypto_markets():
    order_book_comparisons = []
    req = requests.get(CRYPTOWATCH_BASE_URL.format("markets"))
    if req.status_code == 200:
        json_response = json.loads(req.content)
        for market1 in json_response['result']:
            order_book1 = get_order_book_for_market(market1)
            for market2 in json_response['result']:
                if market2['exchange'] == market1['exchange']:
                    # skip all comparisons within the same exchange
                    continue
                if market2['pair'] != market1['pair']:
                    # skip all comparisons that don't have matching pairs
                    continue
                order_book2 = get_order_book_for_market(market2)
                compare_order_books(order_book1, order_book2)
    return order_book_comparisons


def main():
    t0 = time.time()
    while True:
        compare_crypto_markets()
        time.sleep(get_wait_time(t0))


if __name__ == "__main__":
    main()





