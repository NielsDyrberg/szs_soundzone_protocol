
"""
Setup pytest here, to test the module
"""

import threading
import time

from modules.soundzone_client import SoundZoneClient
from modules.soundzone_server import SoundZoneServer


class TestSZP:
    def __init__(self):
        self.szs = SoundZoneServer()
        self.szc = SoundZoneClient()

    def test_check_conn(self):
        server = threading.Thread(target=self.szs.receive)
        client = threading.Thread(target=self.szc.send)

        server.start()
        time.sleep(1)
        client.start()


if __name__ == "__main__":
    test = TestSZP()
    test.test_check_conn()
