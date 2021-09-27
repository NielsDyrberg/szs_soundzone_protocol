
import socket
from modules.soundzone_protocol import SoundZoneProtocol


class SoundZoneServer:
    def __init__(self):
        # obj of szp
        szp = SoundZoneProtocol()

        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.bind((socket.gethostname(), szp.port))
        self.s.listen(5)

    def receive(self):
        while True:
            clientsocket, address = self.s.accept()
            print(f"Connection from {address} has been established!")
            clientsocket.send(bytes("Welcome to the server!", "utf-8"))


if __name__ == "__main__":
    pass
