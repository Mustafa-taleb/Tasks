import requests

x= requests.get('https://s-m.com.sa/')

print (x.status_code)
print (x.headers['content-type'])
print (r.text)
print (r.json())
