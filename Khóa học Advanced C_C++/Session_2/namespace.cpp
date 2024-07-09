#include <cstdio>
#include <string>

namespace str {
	
	const std::string prefix = "(str::string) ";
	
	class string {
		std::string _s = "";
		string ();
		
	public:
		string (const std::string & s) : _s(prefix + s) {
		}
		const char * c_str() const { return _s.c_str();}
		operator std::string & () {
			return _s;
		}
		operator const char * () { 
			return _s.c_str();
		}
	};
} // namespace str

int main() {
	const std::string s1("This is a std::string");
	std::puts(s1.c_str());
	
	const str::string s2(s1);
	std::puts(s2.c_str());
	
	return 0;
}
