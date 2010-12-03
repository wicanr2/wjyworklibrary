#include <peer/peer.hpp>

void peerInfo::Dump() {
	std::cout << *this;
}

std::ostream& peerInfo::Dump(std::ostream &out) {
	int width = 60;
	out<<std::endl; 
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			out << "_";
		}
		out <<std::endl;
	}
	out<<"Index     :" << std::setw(width) << this->GetIndex();
	out<<std::endl; 
	out<<"name      :" << std::setw(width) << this->GetName();
	out<<std::endl; 
	out<<"UUID      :" << std::setw(width) << this->GetUUID();
	out<<std::endl; 
	out<<"IP        :" << std::setw(width) << this->GetIP();
	out<<std::endl; 
	out<<"VideoPort :" << std::setw(width) << this->GetVideoPort();
	out<<std::endl; 
	out<<"AudioPort :" << std::setw(width) << this->GetAudioPort();
	out<<std::endl; 
	out<<"Probing   :" << std::setw(width) << this->GetProbingPort();
	out<<std::endl; 
	out<<"Used      :" << std::setw(width) << this->CheckUsed();
	out<<std::endl; 
	out<<"Avail-BW  :" << std::setw(width) << this->GetCurAvaBW();
	out<<std::endl; 
	{
		for ( int i = 0 ; i < 80 ; i++ ) {
			out << "_";
		}
		out <<std::endl;
	}
	return out;
}	
std::ostream& operator<< ( std::ostream &out, 
			peerInfo &rhs )
{
	rhs.Dump(out);
	return out;
}
