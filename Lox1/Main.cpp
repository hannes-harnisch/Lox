#include "PCH.hpp"

#include "Scanner.hpp"
#include "Token.hpp"

namespace lox
{
	class Lox
	{
		Reporter reporter;

	public:
		void run_file(std::string_view path)
		{
			run(get_file_chars(path));
			if(reporter.had_error())
				std::exit(65);
		}

		void run_prompt()
		{
			while(true)
			{
				std::cout << "> ";
				std::string line;
				std::cin >> line;
				run(line);
				reporter.reset_error();
			}
		}

	private:
		void run(std::string_view source)
		{
			Scanner scanner(reporter, source);

			std::vector<Token> tokens = scanner.scan_tokens();

			for(const auto& token : tokens)
				std::cout << token.to_string();
		}

		static std::string get_file_chars(std::string_view path)
		{
			std::ifstream file(path.data());
			if(file.bad())
				throw std::invalid_argument("No such file.");

			file.seekg(0, std::ios::end);
			size_t length = file.tellg();
			file.seekg(0, std::ios::beg);

			std::string bytes(length, '\0');
			file.read(bytes.data(), length);
			return bytes;
		}
	};
}

int main(int argc, char* argv[])
{
	try
	{
		lox::Lox lox;
		if(argc > 1)
		{
			std::cout << "Usage: jlox [script]";
			std::exit(64);
		}
		else if(argc == 1)
			lox.run_file(argv[0]);
		else
			lox.run_prompt();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
