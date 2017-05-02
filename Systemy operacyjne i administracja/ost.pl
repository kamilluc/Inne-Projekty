#!/usr/bin/perl

#zmienne
$nr_zestawu = 0;
$i = 0;
#czysczenie log
open(LOG, ">log.txt");
print LOG "Co sie dzialo:\n";
close LOG;

#petla glowna
while ()
{
#dla tygodnia 604800
sleep (5);

#aktualizacja www
$nr_zestawu = $nr_zestawu + 1;
#zapis
open(PISZ, ">/home/stud/is2014/kluc/public_html/index.html");

#top
open(CZYT, "<top.txt");

#bottom
open(CZYTA, "<bottom.txt");

#top2
while ($scalar = <CZYT>) 
{
    print PISZ "$scalar";
}



#dodatkowa linia



for ($z = 0; $z < $nr_zestawu; $z++) 
{
$i = $z + 1;
print PISZ "<a href=zestaw$i.pdf>Zestaw $i</a><br />";
}









#dodatkowa linia
#for ($z = 0; $z <= nr_zestawu; $i++) 
#{
#$i = $i + 1;
#   print PISZ "<a href=zestaw$i.pdf>Zestaw $i</a><br />";
#}
#print PISZ "<a href=zestaw$nr_zestawu.pdf>Zestaw $nr_zestawu</a><br />";

#bottom2
while ($scalar = <CZYTA>) 
{
    print PISZ "$scalar";
}

close CZYTA;
close CZYT;
close PISZ;


#dopisanie do top
#open(CZYTB, ">>top.txt");
#print CZYTB "<a href=zestaw$nr_zestawu.pdf>Zestaw $nr_zestawu</a><br />";
#close CZYTB;

#log1
$czas = localtime();
print "aktualizacja WWW: $czas\n";
open(LOG, ">>log.txt");
print LOG "aktualizacja WWW: $czas\n";
close LOG;

#powiadomienie na email
$to = 'proj.perl@gmail.com';
$from = 'kluc@metal.agh.edu.pl';
$subject = "Powiadomienie: $nr_zestawu";
$message = 'Pojawil sie nowy zestaw zadan na: http://sendzimir.metal.agh.edu.pl/~kluc/';

open(MAIL, "|/usr/lib/sendmail -t");

print MAIL "To: $to\n";
print MAIL "From: $from\n";
print MAIL "Subject: $subject\n\n";
print MAIL $message;

close(MAIL);

#log2
$czas = localtime();
print "email potwierdzajacy wyslano: $czas\n";
open(LOG, ">>log.txt");
print LOG "email potwierdzajacy wyslano: $czas\n";
close LOG;
}