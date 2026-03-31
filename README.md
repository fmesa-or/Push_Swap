For see memory leaks use:

valgrind ./program_name

Flags:
	--leak-check=full						->To see details of leaked memory
	--leak-check=full --show-leak-kinds=all -> To see all leaks and where
	--log-fd=1								->??????
	--track-origins=yes						->To see where unitialised values come
	--show-leaks-kinds=all					->??????
	--supressions=supressions.supp			->??????


Also use:

lldb

For correction:
ARG="numbers"; ./push_swap $ARG | ./checker_linux $ARG
ARG="numbers"; ./push_swap $ARG | wc -l
https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php