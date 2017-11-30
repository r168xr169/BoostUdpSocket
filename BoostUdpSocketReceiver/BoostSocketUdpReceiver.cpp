#define _WIN32_WINNT 0x0501

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

int main(int argc, char * argv[])
{	    
	using namespace boost::asio::ip;
	boost::asio::io_service io_service;
	udp::socket sock(io_service, udp::endpoint(udp::v4(), 1234));

	for(int i=0; true; i++)
	{
		boost::array<char, 128> recv_buf;
		udp::endpoint endpoint;
		size_t len = sock.receive_from(boost::asio::buffer(recv_buf), endpoint);
		std::cout.write(recv_buf.data(), len);
	}

	return 0;
}
