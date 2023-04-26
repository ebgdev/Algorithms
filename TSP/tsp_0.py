import itertools
import math

def distance(city1, city2):
    lat1, lon1 = city1[1], city1[2]
    lat2, lon2 = city2[1], city2[2]
    R = 6371
    dLat = math.radians(lat2 - lat1)
    dLon = math.radians(lon2 - lon1)
    a = math.sin(dLat / 2) * math.sin(dLat / 2) + \
        math.cos(math.radians(lat1)) * math.cos(math.radians(lat2)) * \
        math.sin(dLon / 2) * math.sin(dLon / 2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
    d = R * c
    return d

def find_shortest_route(cities):
# Generate all possible permutations of the cities    
    routes = list(itertools.permutations(cities))
    # Calculate the total distance traveled for each permutation
    distances = []
    for route in routes:
        total_distance = 0
        for i in range(len(route)-1):
            total_distance += distance(route[i], route[i+1])
        distances.append(total_distance)
        # Return the route with the shortest distance traveled
    shortest_distance = min(distances)
    shortest_route = routes[distances.index(shortest_distance)]
    return shortest_route, shortest_distance

cities = [('New York', 40.7128, -74.0060),
          ('Los Angeles', 34.0522, -118.2437),
          ('Chicago', 41.8781, -87.6298),
          ('Houston', 29.7604, -95.3698),
          ('Phoenix', 33.4484, -112.0740),
          ('Philadelphia', 39.9526, -75.1652),
          ('San Antonio', 29.4241, -98.4936),
          ('San Diego', 32.7157, -117.1611),
          ('Dallas', 32.7767, -96.7970),
          ('San Jose', 37.3382, -121.8863)]

shortest_route, shortest_distance = find_shortest_route(cities)
print('Shortest route:\n\n', shortest_route)
print('Shortest distance:', shortest_distance, 'km\n')