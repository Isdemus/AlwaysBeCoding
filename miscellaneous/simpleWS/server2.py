import SimpleHTTPServer
import SocketServer

class MyRequestHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):
	def do_GET(self):
		#if self.path == '/':
		#	self.path = '/index.html';
		print("self path: " + self.path);
		if "Query" in self.path:
			print("Query Earned");
		elif self.path == '/':
                        self.path = '/index.html';   
		#self.wfile.write("<h1>TestingFromServer2.py</h1>");
		return SimpleHTTPServer.SimpleHTTPRequestHandler.do_GET(self);

Handler = MyRequestHandler;
server = SocketServer.TCPServer(('0.0.0.0', 8080), Handler);

server.serve_forever();
