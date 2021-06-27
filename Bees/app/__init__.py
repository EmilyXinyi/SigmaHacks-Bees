import os
from flask import Flask, render_template, send_from_directory
from dotenv import load_dotenv

load_dotenv()
app = Flask(__name__)


@app.route('/')
def homepage(): 

    return render_template('homepage.html', url=os.getenv("URL"))

@app.route('/HoneyHouseFarms')
def good(): 
    return render_template('HoneyHouseFarms.html', url=os.getenv("URL"))

@app.route('/hiveLocationB')
def infiltrated(): 
    return render_template('infiltrated.html', url=os.getenv("URL"))

@app.route('/CentralValleyBees')
def CentralValleyBees(): 
    return render_template('CentralValleyBees.html', url=os.getenv("URL"))

@app.route('/MtAdamsHoney')
def MtAdamsHoney(): 
    return render_template('MtAdamsHoney.html', url=os.getenv("URL"))

@app.route('/contact')
def contact(): 
    return render_template('contact.html', url=os.getenv("URL"))

@app.route('/health')
def health(): 
    return 'health works'



