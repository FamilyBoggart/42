DATE = $(shell date +%d-%m-%Y)
open : 
	git status
	git pull

close : 
	git add .
	git commit -m "$(USER) : $(DATE)"
	git push

today: 
	echo $(DATE)
