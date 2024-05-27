## Run
- Execute `docker compose up -d`
- Download go packages
- run `docker exec -it snappfood-1-postgres-1 bash -c "psql -U postgres snappfood"` 
    - Now copy content of the `tables.sql` and paste into the terminal to create the necessary tables.
- Now execute `bash run.sh`

## Usage
- create vendor: `curl localhost:8080/vendor/ -d '{"name":"Yaghoot"}' -v`
- create order for vendor 2: `curl localhost:8080/vendor/2/order -X POST -v`
- create trip for order 2: `curl localhost:8080/order/2/trip -X POST -v`
- update trip 6 status: `curl localhost:8080/trip/6 -d '{"status":"delivered"}' -X PUT  -v`
- report delay for order 12: `curl localhost:8080/order/12/report-delay -X POST  -v`
- create agent: `curl localhost:8080/agent/ -X POST  -v`
- assign delay report to agent 2: `curl localhost:8080/agent/2/assign-delay-report -X PUT -v`


## TODO
- adding indexes to necessary fields
- using db transactions
- proper logging
- connection pooling for Redis and Postgres
- write tests
