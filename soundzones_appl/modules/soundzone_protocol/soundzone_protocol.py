
import socket


class SoundZoneProtocol:
    def __init__(self):
        # setup socket
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    buffer_len = 8  # buffer size in bytes
    PORT = 1695  # port # for tcp
    HEADER_SIZE = 8  # one byte for header size
    ENCODING = "utf-8"

    cid = {
        "checkCon": 1,
        "enroll": 2,  # not defined yet
    }

    def open_port(self, port=PORT):
        """
        Opens port to allow incoming connections
        :param port: TCP port is used
        :return: None
        """
        self.s.bind((socket.gethostname(), port))
        self.s.listen(5)

    def connect(self, port=PORT):
        """
        Connects a socket to another.
        :param port: TCP port is used
        :return: None
        """
        self.s.connect((socket.gethostname(), port))

    def receive(self):
        """
        Prints all received data chunks
        :return: payload
        """
        payload = ""
        new_payload = True
        client_socket, address = self.s.accept()

        while True:
            tmp_payload = client_socket.recv(self.buffer_len)
            if new_payload:
                payload_len = int(tmp_payload[:self.HEADER_SIZE])
                new_payload = False
                print(f"Receiving new payload with len: {payload_len}")

            payload += tmp_payload.decode(encoding=self.ENCODING)

            if len(payload) - self.HEADER_SIZE == payload_len:
                print("Full msg received")
                print(payload[self.HEADER_SIZE:])
                new_payload = True
                payload = ""

    def send(self, msg):
        """
        Sends a msg to pre-connected address
        :param msg: Message to send
        :return: None
        """
        msg = f"{len(msg):<{self.HEADER_SIZE}}"+msg
        self.s.send(bytes(msg, encoding=self.ENCODING))

    def send_to(self, msg, address):
        """
        Future development, so there is no use of a preset connection, but just send the message to a specific addr.

        Send data to the socket. The socket should not be connected to a remote socket, since the destination socket
        is specified by address. The optional flags argument has the same meaning as for recv() above. Return the number of
        bytes sent. (The format of address depends on the address family — see above.)

        Raises an auditing event socket.sendto with arguments self, address.

        Changed in version 3.5: If the system call is interrupted and the signal handler does not raise an exception,
        the method now retries the system call instead of raising an InterruptedError exception
        (see PEP 475 for the rationale).
        """
        pass


if __name__ == "__main__":
    pass
