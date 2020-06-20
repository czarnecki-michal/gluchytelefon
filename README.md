# gluchytelefon

Napisać serię programów komunikujących się ze sobą za pomocą różnych protokołów IPC. Każdy z programów ma za zadanie przed przekazaniem wiadomości przekształcić ją w odpowiedni sposób.
Wszystkie programy powinny być budowane za pomocą makefile'ow (np. autotools, cmake bądź gnu make).. Kod pod kontrolą lokalnego git-a. Sposób uruchamiania dowolny ale zintegrowany (przy użyciu jednej komendy). W przypadku gdy wynik którejś z modyfikacji przekroczy zakres u32, powinna pojawić się o tym informacja na wyjściu. Wejściowa aplikacja "Konsola" przyjmuje liczby do momentu gdy użytkownik wciśnie ctrl+c, wówczas wszystkie programy powinny zostać pozamykane.

> ### Wymagania
>- **Wiadomość**: liczba unsigned 32 bity
>- **Środowisko**: dowolny linux (natywny, bądź zwirtualizowany w virtualbox'ie)

### 1.	"Konsola":
-	Wejście: stdin
-	Modyfikacja/wyjście: x:=x modulo 10
### 2.	"Argument"
-	Wejście: argument do programu parsowany za pomocą getopt
-	Modyfikacja/wyjście: x:= Następna liczba pierwsza 
### 3.	"Pipe"
-	Wejście: Nazwany pipe
-	Modyfikacja/wyjście: x:= ustawienie bitu na pozycji określonej przez x  
### 4.	"Jajko"
-	Wejście: interfejs znakowy (linux kernel module over chrdev)
-	Modyfikacja/wyjście: lustrzane odbicie bitów, np. dla x:= 524288 dec (bin: 00000000000010000000000000000000) dla x = 4096 dec (bin: 00000000000000000001000000000000)
### 5.	"Netlink"
-	Wejście: Generic netlink
-	Modyfikacja/wyjście:	x:= suma cyfr liczby x w postaci dziesiętnej
### 6.	"Sieć"
-	Wejście: Stream tcp
-	Wyjście: stdout na osobnej konsoli -> zmodyfikowana liczba lub info o przekroczeniu zakresu

>### Pomocne linki
>- https://github.com/rikonek/job/
>- https://opensourceforu.com/2015/08/netlink-a-communication-mechanism-in-linux/  
>- https://people.redhat.com/nhorman/papers/netlink.pdf


## Wykonal Michal Czarnecki
