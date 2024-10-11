
import requests
import datetime

MY_LAT = 31.243870
MY_LONG = 34.793991


parameters = {
    "lat" : MY_LAT,
    "lng" : MY_LONG,
}

response = requests.get("https://api.sunrise-sunset.org/json", params = parameters)
response.raise_for_status()
data = response.json()
#print(data)

sunrise = data["results"]["sunrise"]
sunset = data["results"]["sunset"]

sun_rise_set = (sunrise, sunset)

print(sun_rise_set)

time_now = datetime.datetime.now()

formatted_time = time_now.strftime("%I:%M:%S %p")
print(formatted_time)



setelite_response = requests.get("http://api.open-notify.org/iss-now.json")
setelite_response.raise_for_status()
setelite_response_data = setelite_response.json()
latitude = setelite_response_data["iss_position"]["latitude"]
longitude = setelite_response_data["iss_position"]["longitude"]

print(latitude , longitude)

if((MY_LAT - float(latitude)) + (MY_LONG - float(longitude)) <= 10):
    print("I'm seen from space!")
else:
    print("The setelite looking something, but nothing close to me for sure!")