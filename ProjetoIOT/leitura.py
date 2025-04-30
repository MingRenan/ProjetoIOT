import serial
import time
import requests
import re  

porta_serial = serial.Serial('COM4', 9600)
time.sleep(2)

url = 'http://localhost:3000/umidade' 

print("📡 Aguardando dados do Arduino...\n")

try:
    while True:
        if porta_serial.in_waiting:
            leitura = porta_serial.readline().decode('utf-8').strip()
            print(f"Dado recebido: {leitura}")

           
            match = re.search(r'\d+', leitura)
            if match:
                umidade = int(match.group())
                payload = {"umidade": umidade}
                resposta = requests.post(url, json=payload)
                print(f"✅ Enviado para API | Status HTTP: {resposta.status_code}")
except KeyboardInterrupt:
    print("\n🛑 Leitura encerrada.")
    porta_serial.close()
