CREATE TABLE Vendors (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE Orders (
    id SERIAL PRIMARY KEY,
    vendor_id INT REFERENCES Vendors(id),
    time TIMESTAMP NOT NULL
);

CREATE TABLE EstimatedDeliveries (
    id SERIAL PRIMARY KEY,
    time TIMESTAMP NOT NULL,
    order_id INT REFERENCES Orders(id)
);

CREATE TABLE Trips (
    id SERIAL PRIMARY KEY,
    order_id INT UNIQUE REFERENCES Orders(id), -- At most one Trip can be associated with an Order.
    status VARCHAR(20) NOT NULL, 
    deliverd_time TIMESTAMP DEFAULT NULL-- TODO This is a bad design.
);

CREATE TABLE Agents (
    id SERIAL PRIMARY KEY
);

CREATE TABLE DelayReports (
    id SERIAL PRIMARY KEY,
    order_id INT REFERENCES Orders(id),
    report_time TIMESTAMP NOT NULL,
    estimated_delivery INT REFERENCES EstimatedDeliveries(id),
    reason SMALLINT NOT NULL,
    resolved BOOLEAN NOT NULL,
    agent_id INT REFERENCES Agents(id)
);

