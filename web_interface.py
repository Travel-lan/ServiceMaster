from flask import Flask, render_template, jsonify
import os
import psutil

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/install_mariadb')
def install_mariadb():
    os.system("sudo apt-get install -y mariadb-server")
    return "MariaDB успешно установлена!"

@app.route('/install_nginx')
def install_nginx():
    os.system("sudo apt-get install -y nginx")
    return "Nginx успешно установлен!"

@app.route('/monitor_mariadb')
def monitor_mariadb():
    result = os.system("systemctl is-active --quiet mariadb")
    return "MariaDB работает нормально" if result == 0 else "MariaDB не работает"

@app.route('/monitor_nginx')
def monitor_nginx():
    result = os.system("systemctl is-active --quiet nginx")
    return "Nginx работает нормально" if result == 0 else "Nginx не работает"

@app.route('/system_info')
def system_info():
    cpu_usage = psutil.cpu_percent()
    ram_usage = psutil.virtual_memory().percent
    return jsonify(cpu=cpu_usage, ram=ram_usage)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
