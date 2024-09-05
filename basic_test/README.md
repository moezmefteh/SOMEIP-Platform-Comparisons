# Description

The code represents a client-server communication where the client sends a request to the service, and the service responds with a message. Both applications use SOME/IP for messaging. The key steps involve creating a request message on the client side, sending it, and then receiving and handling the response on both sides.

## Client Side

1. **Create a Request**: The client creates a request message using `create_request()`, setting service ID, instance ID, and method ID. It also serializes a payload (here, an array of bytes from 0 to 9) into the message.
2. **Starting the Application**: Since the SOME/IP framework uses an event loop (which doesn’t return), the client starts the application in a separate thread. This allows the client to wait for the availability of the service.
3. **Send Request**: Once the service becomes available (detected via a callback), the client sends the message request.
4. **Handle Response**: The client registers a message handler to process the response received from the service. In the example you provided, the client receives the reversed byte sequence (e.g., 09 08 07 06 05 04 03 02 01 00).

## Service Side

1. **Receive Request**: The service runs a message handler to receive the client’s request. Upon receiving the message, it reads the payload (an array of bytes from 00 to 09).
2. **Send Response**: The service then sends a response message back to the client, which could modify the payload, such as reversing the byte array.
3. **Handle Message**: When the service receives the message, it displays the payload it received from the client (e.g., 00 01 02 03 04 05 06 07 08 09).

## Expected Output

**Service Output**:
    2024-01-16 16:46:30.193933 [info] Client [1000] is connecting to [1001] at /tmp/vsomeip-1001
    2024-01-16 16:46:30.198641 [info] REGISTERED_ACK(1001)
    SERVICE: Received message with Client/Session [1001/0001] 00 01 02 03 04 05 06 07 08 09 
    2024-01-16 16:46:30.287755 [info] REQUEST(1001): [1234.5678:255.4294967295]


**Client Output**:
    CLIENT: Service [1234.5678] is NOT available.
    CLIENT: Received message with Client/Session [1001/0001] 09 08 07 06 05 04 03 02 01 00 
    2024-01-16 16:46:30.295856 [info] ON_AVAILABLE(1001): [1234.5678:0.0]
    CLIENT: Service [1234.5678] is available.


## Key Aspects

- **Event Loop**: The SOME/IP framework uses a non-blocking event loop. This is why the client has to be run in a separate thread to wait for the service availability and send the request.
- **Callback Mechanism**: Both client and service use callbacks to handle incoming messages and availability changes.
- **Payload**: The payload is a simple array of bytes (`std::vector<vsomeip::byte_t>`), which is serialized and sent between the applications. The client sends 09 08 07 06 05 04 03 02 01 00, and the service returns the original or a modified (reversed) payload.
- **Multithreading**: We used threads to handle the non-blocking nature of the SOME/IP event loop and to send the request asynchronously once the service is available.
