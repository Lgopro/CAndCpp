from twilio.rest import Client

account_sid = 'ACa3a7901ee5dd40f0c1406b303d4cf231'
auth_token = '808c9f280b1f23ea5c5d5bd2533d3579'
client = Client(account_sid, auth_token)

message = client.messages.create(
    body = "I know what you did last summer. Натэла это я Леня.",
    from_='+19892827848',
    to='+972524719386'
)

print(message.status)