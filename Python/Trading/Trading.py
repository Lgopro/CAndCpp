import requests
import datetime as dt
from twilio.rest import Client

# replace the "demo" apikey below with your own key from https://www.alphavantage.co/support/#api-key
url = 'https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=TSLA&interval=60min&apikey=LM98JHSZ4VGNLD7U'
r = requests.get(url)
data = r.json()

#print(data)

now = dt.datetime.now()
formatted_date = now.strftime("%Y-%m-%d")
test_time = '2024-10-8'
news = 'https://newsapi.org/v2/everything?q=tesla&from=' + formatted_date +' &sortBy=publishedAt&apiKey=96ecc8cc0b484dd2b54ceb009f9d6eff'
new_data = requests.get(news)
json_data = new_data.json()

# print(json_data)
# print(now)
# print(formatted_date)

# Extract the "open" prices from the time series data
open_prices = [float(values['1. open']) for time, values in data['Time Series (60min)'].items()]
high_prices = [float(values['2. high']) for time, values in data['Time Series (60min)'].items()]
low_prices = [float(values['3. low']) for time, values in data['Time Series (60min)'].items()]


# Find the maximum and minimum "open" prices
max_open = max(open_prices)
min_open = min(open_prices)

max_low = max(open_prices)
min_low = min(open_prices)

max_high = max(open_prices)
min_high = min(open_prices)

account_sid = 'ACa3a7901ee5dd40f0c1406b303d4cf231'
auth_token = '808c9f280b1f23ea5c5d5bd2533d3579'
client = Client(account_sid, auth_token)

message = client.messages.create(
    body = f"Today {formatted_date} The max value is: {max_high} and the min value is: {min_low}",
    from_='+19892827848',
    to='+972524719386'
)

print(message.status)
