'use strict';

module.exports = function(app) {
    var House = app.models.House;
    var collectionName = House.modelName.toLowerCase();

    /**
     * List the details of members from ALASKA from the
     * REPUBLICAN party in chronological order.
     */
    app.get('/query1', function(req, res) {
        var filter = {
            where: {
                STATE: 'ALASKA',
                REP_PARTY: 'REPUBLICAN'
            }
        };
        var t0 = new Date().getTime();
        House.find(filter, function(err, response) {
            var t = new Date().getTime();
            if (err) {
                console.error(err);
            }
            res.send({
                query_execution_time_milliseconds: t - t0,
                query_result: response
            });
        });
    });

    /**
     * List a set of all questions asked in 108th House (no duplicates).
     */
    app.get('/query2', function(req, res) {
        House.getDataSource().connector.connect(function(err, db) {
            if (err) {
                console.error(err);
            }
            var t0 = new Date().getTime();

            db.collection(collectionName).distinct('QUESTION', function(error, response) {
                var t = new Date().getTime();
                if (error) {
                    console.error(error);
                }
                res.send({
                    query_execution_time_milliseconds: t - t0,
                    query_result: response
                });
            });
        });
    });

    /**
     * How many times a member from California(CALIFOR)
     * voted “NAY” (use count).
     */
    app.get('/query3', function(req, res) {
        var filter = {
            VOTE: 'NAY',
            STATE: 'CALIFOR'
        };
        var t0 = new Date().getTime();

        House.count(filter, function(err, response) {
            var t = new Date().getTime();
            if (err) {
                console.error(err);
            }
            res.send({
                query_execution_time_milliseconds: t - t0,
                count: response
            });
        });
    });

    /**
     * Identify the five members with the least number of votes.
     */
    app.get('/query4', function(req, res) {
        House.getDataSource().connector.connect(function(err, db) {
            if (err) console.error(err);

            var pipeline = [
                {
                    "$group": {
                        _id: {
                            name: "$REP_NAME"
                        },
                        count: {
                            "$sum": 1
                        }
                    }
                },
                {
                    "$sort": {
                        count: 1
                    }
                },
                {
                    "$limit": 5
                }
            ];
            var t0 = new Date().getTime();

            db.collection(collectionName)
                .aggregate(pipeline)
                .toArray(function(error, response) {
                    var t = new Date().getTime();
                    if (error) {
                        console.error(error);
                    }
                    res.send({
                        query_execution_time_milliseconds: t - t0,
                        result: response
                    });
            });
        });
    });

    /**
     * Identify the number of representatives for each district and
     * list them in ascending order of the count (count by district).
     */
    app.get('/query5', function(req, res) {
        House.getDataSource().connector.connect(function(err, db) {
            if (err) console.error(err);

            var pipeline = [
                {
                    "$group": {
                        _id: {
                            district: "$CONGR_DISTRICT"
                        },
                        count: {
                            "$sum": 1
                        }
                    }
                },
                {
                    "$sort": {
                        count: 1
                    }
                }
            ];
            var t0 = new Date().getTime();

            db.collection(collectionName)
                .aggregate(pipeline)
                .toArray(function(error, response) {
                    var t = new Date().getTime();
                    if (error) {
                        console.error(error);
                    }
                    res.send({
                        query_execution_time_milliseconds: t - t0,
                        result: response
                    });
            });
        });
    });

    /**
     * Overall, what are the different votes we received in the 108th House
     * and what is the frequency of each of these types of votes?
     * (Calculate the frequency of each type of vote)
     */
    app.get('/query6', function(req, res) {
        House.getDataSource().connector.connect(function(err, db) {
            if (err) console.error(err);

            var pipeline = [
                {
                    "$group": {
                        _id: {
                            vote: "$VOTE"
                        },
                        count: {
                            "$sum": 1
                        }
                    }
                },
                {
                    "$sort": {
                        count: -1
                    }
                }
            ];
            var t0 = new Date().getTime();

            db.collection(collectionName)
                .aggregate(pipeline)
                .toArray(function(error, response) {
                    var t = new Date().getTime();
                    if (error) {
                        console.error(error);
                    }
                    res.send({
                        query_execution_time_milliseconds: t - t0,
                        result: response
                    });
            });
        });
    });

    /**
     * What is the total number of votes received from each state in
     * the 108th house? (calculate state-wise contribution)
     */
    app.get('/query7', function(req, res) {
        House.getDataSource().connector.connect(function(err, db) {
            if (err) console.error(err);

            var pipeline = [
                {
                    "$group": {
                        _id: {
                            state: "$STATE"
                        },
                        count: {
                            "$sum": 1
                        }
                    }
                },
                {
                    "$sort": {
                        count: 1
                    }
                }
            ];
            var t0 = new Date().getTime();

            db.collection(collectionName)
                .aggregate(pipeline)
                .toArray(function(error, response) {
                    var t = new Date().getTime();
                    if (error) {
                        console.error(error);
                    }
                    res.send({
                        query_execution_time_milliseconds: t - t0,
                        result: response
                    });
            });
        });
    });
};
