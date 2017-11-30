#define _WIN32_WINNT 0x0501

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/format.hpp>
#include <boost/thread.hpp>

int main(int argc, char * argv[])
{
	using namespace boost::asio::ip;

	boost::asio::io_service io_service;
	boost::asio::ip::udp::socket sock(io_service, udp::endpoint(udp::v4(), 1234));
	    
	for(int i=0; true; i++)
	{
		
		std::string str = (boost::format("BoostSocketUDP %03d\n") % i).str();
		sock.send_to
		(
			boost::asio::buffer(str),
			boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("192.168.0.68"), 1234)
		);

		std::cout << str;
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
	}

	return 0;
}
