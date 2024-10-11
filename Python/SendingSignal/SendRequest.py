import requests

response = requests.get(url = "http://api.open-notify.org/iss-now.json")
print(response)
response.raise_for_status() #raise an exception if the status will not be 2xx


data = response.json()
print(data)

iss_position = data["iss_position"]
print(iss_position)

longitude = data["iss_position"]["longitude"]
latitude = data["iss_position"]["latitude"]

iss_position = (longitude, latitude)
print(iss_position)