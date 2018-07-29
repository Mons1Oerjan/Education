#Import socket module:
from socket import *
import sys #in order to terminate the program

#Setup server socket:
serverSocket = socket(AF_INET, SOCK_STREAM) #AF_INET => Use IPv4, SOCK_STREAM => TCP

#Set server port:
serverPort = 6789

#Bind server and port:
serverSocket.bind(('', serverPort))

#Let server listen to serverPort:
serverSocket.listen(1)

while True:
	#Establish the connection:
	print 'Ready to serve...'

	#Accept connections:
	connectionSocket, addr = serverSocket.accept()
	try:
		#Get client data:
		messsage = connectionSocket.recv(2048)

		#Get file in GET request:
		filename = messsage.split()[1]

		#Open file stream:
		f = open(filename[1:])

		#Read file stream:
		outputdata = f.read()

		#Send one HTTP header line into socket:
		connectionSocket.send("\nHTTP/1.1 200 0K\nConnection: close\n\n")

		#Send the content of the requested file to the client:
		for i in range(0, len(outputdata)):
			connectionSocket.send(outputdata[i].encode())
		connectionSocket.send("\r\n".encode())

		#Close the connection:
		connectionSocket.close()

	except IOError:
		#Send response message for file not found:
		connectionSocket.send("\nHTTP/1.1 404 Not Found\nConnection: close\n\n<h1>Error 404: File Not Found.</h1>")

		#Close client socket
		connectionSocket.shutdown(SHUT_WR)
		connectionSocket.close()

#Close server socket:
serverSocket.close()

#Terminate the program after sending the corresponding data:
sys.exit()
