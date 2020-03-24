#include <iostream>

#include <docopt/docopt.h>

#include <Hello.h>
#include <counter/Counter.h>

using namespace Hello;

static const char USAGE[] =
	R"(Say hello.

Usage:
  hello [<name>]

Options:
  -h, --help           Show this screen.
  --version            Show version.
)";

int main( int argc, const char * argv[] )
{
	std::map< std::string, docopt::value > args = docopt::docopt(
		USAGE,
	{
		argv + 1, argv + argc
	},
		true,
		"Hello 1.0" );

	std::string name = "";

	if ( args[ "<name>" ] && args[ "<name>" ].isString() )
	{
		name = args[ "<name>" ].asString();
	}
	
	std::cout << Say_Hello( name ) << std::endl;

	std::cout << "La valeur value = " << Counter::value << std::endl;

	// std::cout << "2 La valeur value = " << Counter::value << std::endl;
	// int new_result = Counter::Count();
	// std::cout << "La valeur value est maintenant de = " << new_result << std::endl;


	return 0;
}

