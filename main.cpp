import speech_recognition as sr
import time
from datetime import date
from gpiozero import LED, Buzzer
import pyaudio
bz = Buzzer(14)
r = sr.Recognizer()
mic = sr.Microphone()
led = LED(18)
led.off()
print("hello")
led.on()
time.sleep(1)
led.off()
bz.off()
while True:

    with mic as source:
        print("listening...")
        audio = r.listen(source, phrase_time_limit = 5)
        print("getting there...")
        
    try:
        words = r.recognize_google(audio)
        print("I think you said "+words)
        if("beach" in words or "Beach" in words or "bitch" in words or "Bitch" in words):
            print("profanity detected")
            bz.on()
            led.on()
            time.sleep(1)
            led.off()
            bz.off()

        
    except sr.UnknownValueError:
        print("cannot understand you")
        
    except sr.RequestError as e:
        print("could not request results")
