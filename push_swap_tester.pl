#!/usr/bin/perl
use List::Util 'shuffle', 'min', 'max';

sub pass_or_fail {
	if (scalar(@_) != 2){print("ERROR"); return 1;}

	$input = $NUM;
	my $result = @_[0];
	print_out_logged("@_[1]");

	if ($input == 3) {
		if ($result <= 3){
			print_out_logged("\033[32;1mPASS\033[0m");
		}
		else {
			print_out_logged("\033[31;1mFAIL\033[0m");
			print(" : @numbers");
		}
	}
	elsif ($input == 5) {
		if ($result <= 12){
			print_out_logged("\033[32;1mPASS\033[0m");
		}
		else {
			print_out_logged("\033[31;1mFAIL\033[0m");
			print(" : @numbers");
		}
	}
	elsif ($input == 100) {
		if ($result <= 700) {
			print_out_logged("\033[32;1;7m5 points\033[0m");
		}
		elsif ($result <= 900) {
			print_out_logged("\033[32;1m4 points\033[0m");
		}
		elsif ($result <= 1100) {
			print_out_logged("\033[33;1m3 points\033[0m");
		}
		elsif ($result <= 1300) {
			print_out_logged("\033[33;1m2 points\033[0m");
		}
		elsif ($result <= 1500) {
			print_out_logged("\033[31;1m1 points\033[0m");
		}
		else {
			print_out_logged("\033[31;1mFAIL\033[0m");
		}
	}
	elsif ($input == 500) {
		if ($result <= 5500) {
			print_out_logged("\033[32;1;7m5 points\033[0m");
		}
		elsif ($result <= 7000) {
			print_out_logged("\033[32;1m4 points\033[0m");
		}
		elsif ($result <= 8500) {
			print_out_logged("\033[33;1m3 points\033[0m");
		}
		elsif ($result <= 10000) {
			print_out_logged("\033[33;1m2 points\033[0m");
		}
		elsif ($result <= 11500) {
			print_out_logged("\033[31;1m1 points\033[0m");
		}
		else {
			print_out_logged("\033[31;1mFAIL\033[0m");
		}
	}
	else{
		print_out_logged("\033[0m\033[37;2m-\033[0m");
	}
}

sub print_stats {
	$n = scalar(@_);
	$sum = 0;
	if ($n == 0) {
		print("Number List Empty, \$n == 0\n"); exit (1);
	}
	foreach $item (@_) {
		$sum += $item;
	}
	$average = $sum / $n;
	$/ = ' ';
	$min = min(@_); $min =~ s/\n//g;
	$max = max(@_); $max =~ s/\n//g;
	print_out_logged("\n\033[34;1mInput Size : ".$NUM."\nMin "."$min"."\nMax "."$max"."\nAverage : $average\033[0m\n");

	$input = $NUM;
	print_out_logged("\n\033[33;1mPass or Fail ?\033[0m\n");
	pass_or_fail($max, "Max : ");
	print_out_logged("\n");
	pass_or_fail($average, "Average : ");
	print_out_logged("\n");

}

sub gen_list {
	$hardcore_mode = 0;
	$Max = $NUM;
	$RndMax = 0;
	if ($hardcore_mode){
		$RndMax = $Max * 10;
	}
	# $index=-$NUM/2;
	$index=-1;
	for($i = 0; $i < $Max; $i++)
	{
		$tmp = 1 + int(rand() * $RndMax);
		$index += $tmp;
		if ($hardcore_mode && (rand() * 5) % 5 == 0) {
			push(@numbers, -$index);
		}
		else {
			push(@numbers, $index);
		}
	}
}

sub	list_check_sorted {
	my $not_sorted = 0;
	for ($i = 0; $i < ((scalar @numbers) - 1); $i++) {
		if ($numbers[i] < $numbers[i + 1]) {
			$not_sorted = 1;
		}
	}
	return ($not_sorted)
}

sub generate_numbers {
	gen_list();
	while (list_check_sorted()) {
		@numbers = shuffle(@numbers);
	}
}

if ((scalar @ARGV) != 2)
{
	print "Usage :\nperl $0 [StackSize] [NumTests]\n";
	exit 0;
}

sub print_out_logged {
	$string = sprintf(shift, @_ );
	print($string);
	$string =~ s/\x1b\[[0-9;]*m//g;
	print(LOGFILE $string);
}

sub print_wait_anim {
	if ($test % $width == 0 && $test != 0){
		$direction++;
		if ($direction > 3){$direction = 0;}
	}
	if ($direction == 0) {
		$pad_left = ($test % $width) - $width;
		$progress = $width + ($test % $width) - $width;
		$pad_right = $width - ($test % $width);
	}
	elsif ($direction == 1) {
		$pad_left = ($test % $width);
		$progress = $width - ($test % $width);
		$pad_right = $pad_left - $width;
	}
	elsif ($direction == 2) {
		$pad_left = $width - ($test % $width);
		$progress = ($test % $width);
		$pad_right = 0;
	}
	elsif ($direction == 3) {
		$pad_left = ($test % $width) - $width;
		$progress = $width - ($test % $width);
		$pad_right = $width + ($test % $width) - $width;
	}

	my $calc = (1 + ($progress % 6));
	print("["."\033[0m\033[37;2m." x $pad_left ."\033[0m\033[3$calc;1m@" x $progress."\033[0m\033[37;2m." x $pad_right."\033[0m] ");
	# print("\tW $width L $pad_left  P $progress R $pad_right D $direction\n");
}

$NUM = @ARGV[0];
$NUM_TEST = @ARGV[1];

$width_max = 100;

$logfilename = ".push_swap_test_results.log";
open(LOGFILE, ">".$logfilename) or die "\033[31;1mError\nCannot create ".$logfilename."\033[0m\n";

$direction = 0;
for ($test = 0; $test < $NUM_TEST; $test++)
{
	$width = 5 + $NUM_TEST / 100 ;

	if ($width > $width_max) {$width = $width_max;};
	print_wait_anim();
	my $calc = int(2 + (($test) % 6));
	print_out_logged("\033[3".$calc.";1m[%-4d / %4d]", ($test + 1), $NUM_TEST);

	@numbers = ( );
	generate_numbers();

	$cmd = "./push_swap ".join(' ', @numbers)." | ./checker ".join(' ', @numbers);
	$res = `$cmd`;
	if ($res eq "KO\n")	{
		print "\n\033[31;1mKO Checker\033[0m"." " x 50 ."\n";
		print "@numbers\n\n"; exit 1;
	}
	$cmd = "./push_swap ".join(' ', @numbers)." | wc -l";
	$res = `$cmd`;
	push(@results, $res);

	$res =~ s/\n//g;
	print_out_logged(" InputSize %4d InstrCount %6d", $NUM, $res);
	pass_or_fail($res, "\033[0m\033[37;2m Pass or Fail ? \033[0m");
	print(LOGFILE "\n@numbers");
	print(LOGFILE "\n");
	print(" " x 50 ."\n");
}
print_stats(@results);
close(LOGFILE) or die "\033[31;1mError\nCannot close ".$logfilename."\033[0m\n";

print("\nMore details : \n\033[34;1m$logfilename\033[0m\n");
