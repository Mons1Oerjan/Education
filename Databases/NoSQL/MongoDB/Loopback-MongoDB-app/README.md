# NodeJS Client App
App to connect to cloud / local DBs and perform simple queries.

## Dependencies
- node
- npm

## Run Project
- `npm install` installs dependencies
- `npm start` starts the web server

## Connect to Local DB
Replace the content of `server/datasources.json` with this:
```
{
  "db": {
    "name": "db",
    "host": "localhost",
    "database": "house",
    "port": 27017,
    "connector": "mongodb",
    "url": ""
  }
}
```
Note: This only works if you have a local MongoDB instance running with the 108thHouse data imported into a collection called 'house'.

## Connect to Cloud DB
Replace the content of `server/datasources.json` with this:
```
{
  "db": {
    "port": 27017,
    "database": "house",
    "name": "mongodb",
    "connector": "mongodb",
    "url": "mongodb://admin:admin123@cluster0-shard-00-00-vtov4.mongodb.net:27017,cluster0-shard-00-01-vtov4.mongodb.net:27017,cluster0-shard-00-02-vtov4.mongodb.net:27017/test?ssl=true&replicaSet=Cluster0-shard-0&authSource=admin&retryWrites=true"
  }
}
```

## Routes
- localhost:3000/query1
- localhost:3000/query2
- localhost:3000/query3
- localhost:3000/query4
- localhost:3000/query5
- localhost:3000/query6
- localhost:3000/query7

## Query Code
All query code is defined in `server/boot/routes.js`
