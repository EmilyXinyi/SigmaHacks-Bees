import os
from flask import Flask, render_template, send_from_directory
from dotenv import load_dotenv

load_dotenv()
app = Flask(__name__)


@app.route('/')
def homepage(): 

    return render_template('homepage.html', url=os.getenv("URL"))

@app.route('/hiveLocationA')
def good(): 
    return render_template('good.html', url=os.getenv("URL"))

@app.route('/hiveLocationB')
def infiltrated(): 
    return render_template('infiltrated.html', url=os.getenv("URL"))

@app.route('/health')
def health(): 
    return 'health works'



