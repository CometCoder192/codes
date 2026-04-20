def scheduleFlights(flights):
    # Sort by end time
    flights.sort(key=lambda x: x[2])

    selectedFlights = []
    lastEndTime = -1

    for flight in flights:
        flightId, start, end = flight

        if start >= lastEndTime:
            selectedFlights.append(flight)
            lastEndTime = end

    return selectedFlights


# Example flights: (ID, start, end)
flights = [
    ("F1", 1, 4),
    ("F2", 2, 6),
    ("F3", 4, 7),
    ("F4", 5, 9),
    ("F5", 8, 10)
]

result = scheduleFlights(flights)

print("Scheduled Flights:")
for f in result:
    print(f)