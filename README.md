# ZPR-Projekt
Projekt z przedmiotu ZPR - Zaawansowane Programowanie w C++

Autorzy:
- Julia Kłos
- Jakub Sikora


# Jak uruchomić aplikację 

Wymagane programy:
- `scons`
- `g++`/`Visual Studio C++`

- `python3.6`
- `pip`
- `pipenv`

- `node`
- `npm`

Programy opcjonalne:
- `astyle`
- `doxygen`
- `psql`
- `jest`
- `make`
- `pytest`
- `newman`
- `selenium-side-runner`
- `git`
- `google chrome`
- `pdflatex`

Wymagane zainstalowane biblioteki:
- `boost 1.69`
- `libpqxx`

## Linux 

### Przygotowanie środowiska
Aby uruchomić aplikację w systemie Linux należy najpierw ją pobrać z repozytorium z serwisu 
github.com. Po pobraniu repozytorium należy upewnić się że obie wymienione wcześniej biblioteki
są skompilowane i zainstalowane w znanej lokalizacji.

W pierwszej kolejności, należy utworzyć plik `.env`, który celowo nie został umieszczony w 
repozytorium ze względów bezpieczeństwa i swojej różnorodności względem środowisk uruchomieniowych.
W nim należy utworzyć zmienne środowiskowe `BOOST_CPPPATH`, `BOOST_LIBPATH`, `PYTHON_CPPPATH`, `PYTHON_LIBPATH`,
`PQXX_CPPPATH` oraz `PQXX_LIBPATH` a jako ich wartości ustawić ścieżki do zainstalowanych bibliotek:
do zmiennych typu `*_CPPPATH` ustawić ścieżki do folderów `include` z plikami nagłówkowymi a do zmiennych typu `*_LIBPATH` ścieżki
do folderów `lib` z skompilowanymi bibliotekami.

Dodatkowo, w pliku `.env` należy utworzyć kolejne zmienne środowiskowe `PROD_DB_HOST`, `PROD_DB_USER`, `PROD_DB_PASSWORD` i
`PROD_DB_PORT` z kolejno hostem bazy danych, użytkownikiem i hasłem do uwierzytelnienia oraz portem na którym nasłuchuje
silnik bazy danych. Dodatkowo, w przypadku gdy będziemy chcieli uruchamiać również środowisko testowe z oddzielną bazą 
danych, należy utworzyćzmienne `DEBUG_DB_HOST`, `DEBUG_DB_USER`, `DEBUG_DB_PASSWORD` i `DEBUG_DB_PORT`.

Po utworzeniu pliku `.env`, należy otworzyć wirtualne środowisko za pomocą polecenia `pipenv shell`. Przy pierwszym wywołaniu tego
polecenia powinno utworzyć się wirtualne środowisko języka Python, z wczytanymi zmiennymi środowiskowymi z pliku `.env`. Po utworzeniu
środowiska należy wykonać polecenia `pipenv update`, które zainstaluje wszystkie wymagane pakiety języka Python.

Wszystkie dalej opisane czynności, włącznie z uruchamianiem aplikacji, muszą być wykonywane w środowisku wirtualnym. Aplikacja
konfiguruje swoje działanie na podstawie zmiennych środowiskowych, dlatego ich obecność jest niezbędna do poprawnego uruchomienia.

### Kompilacja modułu
W kolejnym kroku należy skompilować moduł `scada` napisany w języku C++. Aby to zrobić, może wykonać polecenie `make`, `make scada` lub 
przejść do folderu `/scada` i tam wywołać polececnie `scons`. W przypadku poprawnie wypełnionych zmiennych
środowiskowych z ścieżkami bezwzględnymi, spowoduje to skompilowanie modułu. 

### Uruchomienie serwera aplikacji
Po skompilowaniu biblioteki, można już uruchomić serwer aplikacji. Do uruchomienia aplikacji z bazą produkcyjną, należy wykonać
polecenie `python main.py`. W przypadku chęci uruchomienia aplikacji w trybie deweloperskim, należy wykonać polecenie z odpowiednią
flagą tj. `python main.py -d`. 

### Uruchomienie serwera klienckiego
W celu uruchomienia klienta, należy z głownego folderu projektu przejść do folderu `client` i tam wykonać polecenie `npm start`.
Spowoduje to skompilowanie aplikacji klienckiej i uruchomienie jej na serwerze pod adresem `localhost:3000`. Port można zmienić
ustawiając zmienną środowiskową `PORT` w pliku `.env`. 

### Testy aplikacji
*** Wszystkie foldery zawierające testy kodu źródłowego poprzedzone są __ w celu umieszczenia ich na samej górze folderu ***
Wraz z kompilacją modułu `scada`, kompilują się testy przygotowane w oparciu o bibliotekę `boost_unit_test_framework`. Kody źródłowe testów, wraz
ze zbudowaną aplikacją testową znajdują się w folderze `scada\__tests__`. Aby ją uruchomić, można wejść do omawianego folderu i ręcznie uruchomić 
aplikację z poziomu terminala lub w głównym folderze projektu wykonać polecenie `make cpp_test`, które uruchomi testy.

Aby uruchomić testy części serwera aplikacji napisanej w języku Python należy w głównym folderze projektu wywołać polecenie 
`pytest --ignore=scada` lub po prostu `make python_test`.

W celu uruchomienia testów aplikacji klienckiej należy w folderze `client` wykonać polecenie `npm test` lub w głównym folderze 
projektu wykonać polecenie `make client_test`.

Dodatkowo, przygotowane zostało środowisko do testowania REST API, przy pomocy programu `Postman`. Oferuje on wtyczkę `newman`
umożliwiającą uruchomienie testów REST API przy pomocy terminala, bez okna graficznego. Zestaw przygotowanych testów znajduje się 
w pliku `ZPR.postman_collection.json`. Aby uruchomić testy należy wykonać polecenie `newman run ZPR.postman_collection.json`
lub krócej `make rest_test`. Przed uruchomieniem tego testu należy upewnić się że serwer aplikacji jest uruchomiony i pracuje na
porcie `3000`.

Ostatecznie, przygotowano dodatkowe automatyczne testy aplikacji klienckiej przy wykorzystaniu Selenium. Selenium to narzędzie 
do automatycznego testowania interfejsów graficznych, pozwalające na pisanie skryptów na podstawie których Selenium "udaje"
użytkownika i "wyklikuje" przygotowane scenariusze. Nagrane scenariusze testowe zostały zapisane do pliku `ZPR-Projekt.side` 
Aby uruchomić te testy należy wykonać polecenie `selenium-side-runner -c "browserName=chrome chromeOptions.args=[headless]" ZPR-Projekt.side`.
Argument `headless` pozwala na wykonywanie tych testów bez jawnego otwierania przeglądarki internetowej. Przed uruchomieniem tego testu
należy upenić się że serwer kliencki jest uruchomiony i pracuje na porcie `5000`.

Dodatkowo, istnieje możliwość uruchomienia wszystkich testów równocześnie, przy pomocy prostego polecenie `make test`.

### Generacja dokumentacji
Aby wygenerować dokumentację z kodu źródłowego, można skorzystać z polecenia `doxygen`, wywołanego w głównym folderze projektu. Spowoduje
to wygenerowanie dokuemntacji w folderze `docs/doxygen` w dwóch wersjach: `html` oraz `latex`. Aby zobaczyć wersję `html` należy w przeglądarce
otworzyć plik `index.html`. Aby przejrzeć dokumentację w wersji `latex` należy najpierw skompilować dokumentację przy użyciu polecenia `pdflatex`
lub innego silnika języka `TeX` (np `lualatex`). Po skompilowaniu, zostanie utworzony plik `refman.pdf` z aktualną wersją dokumentacji. 


### Automatyczny linter 
Środowisko umożliwia również kontrolę nad stylem kodu źródłowego. Polecenie `make lint` spowoduje wykonanie polecenia 
`astyle --project "scada/src/*.cpp" "scada/include/*.hpp"`, które dokona formatowania wszystkich plików źródłowych aplikacji.

## Windows

Aplikacja jest przystosowana do pracy jak i na systemie Linux jak i na systemie Windows. Aby uruchomić aplikację 
na systemie Windows należy wykonać wszystkie czynności opisanne w sekcji wyżej, tak samo jak dla systemu Linux.
Jedyną różnicą jest niekompatybilność pliku `Makefile` z systemem Windows, dlatego też aktualnie nie jest możliwym 
korzystanie ze skróconych poleceń typu `make ***`. 


## Szczegóły dotyczące bibliotek
W trakcie przygotowywania biblioteki Boost należy zwrócić uwagę na problem związany z biblioteką
`Boost.Python`. Docelowo, biblioteka ta jest przygotowana do pracy z Pythonem 2. Aby przygotować poprawnie tą bibliotekę,
należy w trakcie konfiugrowania kompilacji przy pomocy polecenia `./bootstrap.sh` dopisać flagę `--using-python 3.6`.
