import socket
import threading
from queue import Queue

target = "127.0.0.1"
start_port = 1
end_port = 1024

def scan_port(port):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(1)
        result = sock.connect_ex((target, port))
        if result == 0:
            print(f"Port {port} is open.")
        sock.close()
    except KeyboardInterrupt:
        exit()
    except:
        pass

def port_scan():
    for port in range(start_port, end_port + 1):
        thread = threading.Thread(target=scan_port, args=(port,))
        thread.start()

def main():
    port_scan()

if __name__ == "__main__":
    main()
