
import socket

from modules.soundzone_protocol import SoundZoneProtocol


class SoundZoneClient:
    def __init__(self):
        # obj of szp
        self.szp = SoundZoneProtocol()
        # setup socket
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.connect((socket.gethostname(), self.szp.port))

    def send(self):
        msg = self.s.recv(self.szp.buffer_len)
        msg = msg.decode("utf-8")
        print(msg)
        return msg


if __name__ == "__main__":
    pass
