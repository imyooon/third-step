#! /usr/bin/env ruby

require "numo/narray"

sci =Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
eng = Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

sciz = []
engz = []

20.times{|i|
	sciz[i] = (sci[i]-sci.mean)/sci.stddev*10+50
	engz[i] = (eng[i]-eng.mean)/eng.stddev*10+50
}

printf("理科\n 平均点: %f \n 標準偏差: %f \n 合計点: %f \n
",sci.mean,sci.stddev,sci.sum)

printf("英語\n 平均点: %f \n 標準偏差: %f \n 合計点: %f \n
",eng.mean,eng.stddev,eng.sum)

printf("理科の偏差値\n")
20.times{|i|
	printf('%f, ',sciz[i])
}
printf("\n")
printf("英語の偏差値\n")
20.times{|i|
        printf('%f, ',engz[i])
}
printf("\n")
sc = sci.sort.reverse
en = sci.sort.reverse
printf("理科の高い順\n")
sc.each do |i|
	puts i 
end
printf("\n")
printf("英語の高い順\n")
sc.each do |i|
        puts i
end
printf("\n")
