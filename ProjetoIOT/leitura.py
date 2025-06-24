import serial
import time
import requests
import re
import threading

porta_serial = serial.Serial('COM4', 9600)
time.sleep(2)

url_umidade = 'http://localhost:3000/umidade'
url_comando = 'http://localhost:3000/comando'

def ler_serial():
    while True:
        if porta_serial.in_waiting:
            leitura = porta_serial.readline().decode('utf-8').strip()
            print(f"\n📥 Dado recebido: {leitura}")

            match = re.search(r'\d+', leitura)
            if match:
                umidade = int(match.group())
                payload = {"umidade": umidade}
                try:
                    resposta = requests.post(url_umidade, json=payload)
                    print(f"✅ Enviado para API | Status HTTP: {resposta.status_code}")
                except requests.exceptions.RequestException as e:
                    print(f"❌ Erro ao enviar para API: {e}")

def buscar_comandos():
    while True:
        try:
            res = requests.get(url_comando)
            comando = res.json().get("comando")
            if comando:
                porta_serial.write((comando + '\n').encode('utf-8'))
                print(f"📤 Comando enviado ao Arduino: {comando}")
        except Exception as e:
            print("⚠️ Erro ao consultar comando:", e)
        time.sleep(2)

try:
    print("📡 Aguardando dados do Arduino...\n")

    thread_leitura = threading.Thread(target=ler_serial, daemon=True)
    thread_comandos = threading.Thread(target=buscar_comandos, daemon=True)

    thread_leitura.start()
    thread_comandos.start()

    while True:
        time.sleep(1)

except KeyboardInterrupt:
    print("\n🛑 Encerrando...")
    porta_serial.close()
