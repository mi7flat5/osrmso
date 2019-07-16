from ctypes import * 
import sys
class Router():
	def __init__(self,_path):

		self.lib = cdll.LoadLibrary("/home/shane/CLionProjects/osrm_dll/cmake-build-debug/libosrm_dll_ch.so")
		self.lib.DoRoute.restype = c_char_p
		self.data_path = _path
		self.initialized = self.initRouter()
		self.result = ''
	def initRouter(self):
		print(self.data_path)
		self.lib.initRouter(self.data_path.encode())
		return True
	def do_route(self,src,dst):
		self.result= ''
		in_data1 = (c_double * len(src))(*src)
		in_data2 = (c_double * len(dst))(*dst)
		res = create_string_buffer(10000000)
		newres = self.lib.DoRoute(in_data1,in_data2,res, sizeof(res))
		return res.value.decode('utf-8')
