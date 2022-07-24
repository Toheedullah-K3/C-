from traceback import print_tb
from urllib.request import urlcleanup
import pyttsx3
import datetime
import speech_recognition as sr
import pyaudio
import wikipedia
import webbrowser
import os
import smtplib

from wikipedia import exceptions


chrome_path = '"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe" %s'
webbrowser.get(chrome_path)

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')

# print(voices[1].id)
engine.setProperty('voices', voices[0].id)
#print(coices[0].id)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("Good Morning Sir")
    elif hour >= 12 and hour < 18:
        speak("Good Afternoon Sir")
    else:
        speak("Good Evening Sir")

    speak("I am Jarvis Sir! Please tell me How may i help you?")

def takeCommand():
    r = sr.Recognizer()

    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print("User Said:", query)

    except Exception as e:
        # print(e)
        print('say that again please')
        return "None"
    return query

def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('toheedullah8820@gmail.com', 'Tktoheedkhan.tk5426')
    server.sendmail('toheedullah8820@gmail.com', to , content)
    server.close()


if __name__ == '__main__':
    
    # wishMe() 
    while 1:
        query = takeCommand().lower()
        #logic for executing task based on query
        if "wikipedia" in query:
            speak("Searching Wikipedia...")
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences = 2)
            speak("According to Wikipedia")
            print(results)
            speak(results)

        elif 'open youtube' in query:
            webbrowser.open('https://www.youtube.com')

        elif 'open google' in query:
            webbrowser.open('https://www.google.com')

        elif 'open stack overflow' in query:
            webbrowser.open('https://www.stackoverflow.com')

        elif 'open' in query:
            print(query)
            url = ('https://www.' +query+ '.com')
            url_new = url.replace('open ' , "")
            urL = url_new.replace(" ", "")
            print(urL)
            webbrowser.open(url_new)
        
        elif "calculus" in query:
            speak("Calculas ki Gaand Maaro")

        

        elif 'open music' in query:
            pass

        elif "time" in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"Sir, The Time is {strTime}")
            print(strTime)

        elif "open code" in query:
            path = ""
            os.startfile(path)
        
        elif "send email" in query:
            try:
                names = {
                    'Inam' : 'enamulhaq786@gmail.com',
                    'jawad' : 'mr.em.jay.official@gmail.com',
                    'tohid' : 'toheedullah002@gmail.com'
                }
                speak("please tell me email?") 
                name = takeCommand().lower() 

                speak("What Should i Say?")
                content = takeCommand()

                
                print(name)

                for k,v in names.items():
                    if name in k:
                        print(v)
                        to = v
                        print(f"ffffffffffffff {to}") 

                # to = "mr.em.jay.official@gmail.com" 
                sendEmail(to, content)

            except exceptions as e:
                print(e)
                speak("Sorry Sir, I did not work properly this time please command me again!")
