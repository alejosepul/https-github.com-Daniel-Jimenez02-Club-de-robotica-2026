from machine import Pin
import utime

motor_izq_adelante = Pin(4, Pin.OUT)
motor_izq_atras = Pin(5, Pin.OUT)
motor_der_adelante = Pin(6, Pin.OUT)
motor_der_atras = Pin(7, Pin.OUT)

sensor_linea_izq_adelante = Pin(16, Pin.IN)
sensor_linea_der_atras = Pin(0, Pin.IN)
sensor_linea_izq_atras = Pin(22, Pin.IN)
sensor_linea_der_adelante = Pin(15, Pin.IN)

trig = Pin(10, Pin.OUT)
echo = Pin(11, Pin.IN)

def avanzar():
    motor_izq_adelante.on()
    motor_izq_atras.off()
    motor_der_adelante.on()
    motor_der_atras.off()

def retroceder():
    motor_izq_adelante.off()
    motor_izq_atras.on()
    motor_der_adelante.off()
    motor_der_atras.on()

def girar_izquierda():
    motor_izq_adelante.off()
    motor_izq_atras.on()
    motor_der_adelante.on()
    motor_der_atras.off()

def girar_derecha():
    motor_izq_adelante.on()
    motor_izq_atras.off()
    motor_der_adelante.off()
    motor_der_atras.on()

def detener():
    motor_izq_adelante.off()
    motor_izq_atras.off()
    motor_der_adelante.off()
    motor_der_atras.off()

def medir_distancia():
    trig.low()
    utime.sleep_us(2)
    trig.high()
    utime.sleep_us(10)
    trig.low()

    while echo.value() == 0:
        inicio = utime.ticks_us()
    while echo.value() == 1:
        fin = utime.ticks_us()

    duracion = utime.ticks_diff(fin, inicio)
    distancia = (duracion * 0.0343) / 2
    return distancia

print("Iniciando")

while True:
    linea_izq_adelante = sensor_linea_izq_adelante.value()
    linea_der_adelante = sensor_linea_der_adelante.value()
    linea_izq_atras = sensor_linea_izq_atras.value()
    linea_der_atras = sensor_linea_der_atras.value()
    distancia = medir_distancia()
    if linea_izq_adelante == 1 and linea_der_adelante == 1:
        retroceder()
        utime.sleep(0.4)
    elif linea_izq_atras == 1 and linea_der_atras == 1:
        avanzar()
        utime.sleep(0.4)
    elif linea_der_adelante == 1 and linea_der_atras == 1:
        girar_izquierda()
        utime.sleep(0.4)
        avanzar()
        utime.sleep(0.4)
    elif linea_izq_adelante == 1 and linea_izq_atras == 1:
        girar_derecha()
        utime.sleep(0.4)
        avanzar()
        utime.sleep(0.4)
    elif distancia < 30:
        avanzar()
    else:
        girar_izquierda()
