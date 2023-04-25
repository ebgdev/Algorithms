import itertools
import math

def distance(city1, city2):
    # Haversine formula to calculate great-circle distance
    lat1, lon1 = city1[1], city1[2]
    lat2, lon2 = city2[1], city2[2]
    R = 6371  # radius of the Earth in kilometers
    dLat = math.radians(lat2 - lat1)
    dLon = math.radians(lon2 - lon1)
    a = math.sin(dLat / 2) * math.sin(dLat / 2) + \
        math.cos(math.radians(lat1)) * math.cos(math.radians(lat2)) * \
        math.sin(dLon / 2) * math.sin(dLon / 2)
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
    d = R * c
    return d