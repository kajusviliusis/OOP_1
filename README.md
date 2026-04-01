## Programos aprašymas

Programa skirta apdoroti studentų duomenis ir analizuoti jų akademinius rezultatus. Ji leidžia:

- Įvesti studentų duomenis rankiniu būdu
- Įvesti vardus ir pavardes, o pažymius sugeneruoti atsitiktinai
- Atsitiktinai generuoti studentų vardus, pavardes ir pažymius
- Nuskaityti studentų duomenis iš failo
- Sugeneruoti failą su atsitiktiniais studentų duomenimis

Programoje taip pat įgyvendintos trys strategijos, skirtos palyginti programos veikimo laiką naudojant skirtingus konteinerius (vector, list, deque) skirstant studentus į pažangius ir nepažangius.

## Naudojimosi instrukcijos

Įsiinstaliuokite CMake, C++ kompiliatorių.

1. Klonuoti projektą:

```
git clone https://github.com/kajusviliusis/OOP_1.git
cd OOP_1
```
2. Sukurti build directory ir kompiliuoti su CMake:
```
mkdir build
cd build
cmake ..
cmake --build .
```

3. Paleisti programą:
```
./OOP_1
```

## Kompiuterio specifikacijos
- Procesorius: Intel Core i5-12450H, 8 branduoliai
- RAM: 16 GB
- SSD: 512 GB

## Strategijų aprašymai:
1. Bendras studentų konteineris (vector, list, deque) padalijamas į du naujus konteinerius: pažangių ir nepažangių studentų.
2. Iš bendro konteinerio į nepažangiųjų konteinerį perkeliami tik nepažangūs studentai, tuo pačiu jie pašalinami iš pradinio konteinerio. Ši strategija taupo atmintį, tačiau dažni trynimai gali būti neefektyvūs kai kuriems konteineriams.
3. Antroji strategija optimizuojama naudojant Standard Template Library (STL) funkcijas.

## 2 Tyrimas su skirtingais konteineriais (1 Strategija)
| Studentų kiekis faile | Konteinerio tipas | Nuskaitymas | Rikiavimas | Skirstymas | Programos veikimas |
| --------- | ----------------- |-------------| ---------- | ---------- | ------------------ |
| 1 000 | Vector | 0.0077 s | 0.0009 s | 0.0003 s | 0.0089 s |
| 1 000 | Deque | 0.0060 s | 0.0009 s | 0.0002 s | 0.0070 s |
| 1 000 | List | 0.0064 s | 0.0003 s | 0.0003 s | 0.0071 s |
| |
| 10 000 | Vector | 0.0278 s | 0.0057 s | 0.0021 s | 0.0356 s |
| 10 000 | Deque | 0.0244 s | 0.0066 s | 0.0009 s | 0.0318 s |
| 10 000 | List | 0.0275 s | 0.0028 s | 0.0024 s | 0.0326 s |
| |
| 100 000 | Vector | 0.2686 s | 0.0707 s | 0.0299 s | 0.3692 s |
| 100 000 | Deque | 0.2702 s | 0.0867 s | 0.0162 s | 0.3732 s |
| 100 000 | List | 0.2763 s | 0.0430 s | 0.0275 s | 0.3469 s |
| |
| 1 000 000 | Vector | 2.6326 s | 0.9120 s | 0.2963 s | 3.8409 s |
| 1 000 000 | Deque | 2.6891 s | 1.1244 s | 0.2413 s | 4.0548 s |
| 1 000 000 | List | 2.6384 s | 0.8569 s | 0.2822 s | 3.7776 s |
| |
| 10 000 000 | Vector | 27.4594 s | 12.3457 s | 3.2338 s | 43.0389 s |
| 10 000 000 | Deque | 26.6834 s | 14.1108 s | 2.7759 s | 43.5701 s |
| 10 000 000 | List | 26.7975 s | 13.4310 s | 2.8425 s | 43.0711 s |

## 2 Strategija
| Studentų kiekis faile | Konteinerio tipas | Nuskaitymas | Rikiavimas | Skirstymas | Programos veikimas |
|----------------------|------------------|-------------|------------|------------|--------------------|
| 1 000 | Vector | 0.0038 s | 0.0008 s | 0.0005 s | 0.0051 s |
| 1 000 | Deque  | 0.0039 s | 0.0008 s | 0.0005 s | 0.0053 s |
| 1 000 | List   | 0.0075 s | 0.0004 s | 0.0002 s | 0.0081 s |
|      |         |           |            |            |            |
| 10 000 | Vector | 0.0344 s | 0.0094 s | 0.0069 s | 0.0507 s |
| 10 000 | Deque  | 0.0280 s | 0.0100 s | 0.0066 s | 0.0446 s |
| 10 000 | List   | 0.0344 s | 0.0032 s | 0.0022 s | 0.0398 s |
|      |         |           |            |            |            |
| 100 000 | Vector | 0.3173 s | 0.1225 s | 0.0938 s | 0.5336 s |
| 100 000 | Deque  | 0.2955 s | 0.1325 s | 0.1035 s | 0.5316 s |
| 100 000 | List   | 0.3381 s | 0.0513 s | 0.0373 s | 0.4267 s |
|      |         |           |            |            |            |
| 1 000 000 | Vector | 2.5307 s | 1.1932 s | 0.9592 s | 4.6831 s |
| 1 000 000 | Deque  | 2.3908 s | 1.3300 s | 1.0175 s | 4.7383 s |
| 1 000 000 | List   | 2.5665 s | 0.6450 s | 0.4668 s | 3.6783 s |
|      |         |           |            |            |            |
| 10 000 000 | Vector | 21.3336 s | 12.5009 s | 10.7202 s | 44.5548 s |
| 10 000 000 | Deque  | 20.7302 s | 13.0062 s | 11.4046 s | 45.1411 s |
| 10 000 000 | List   | 20.4890 s | 7.8812 s | 6.0447 s | 34.4148 s |

## 3 Strategija
| Studentų kiekis faile | Konteinerio tipas | Nuskaitymas | Rikiavimas | Skirstymas | Programos veikimas |
| --------- | ----------------- |-------------| ---------- | ---------- | ------------------ |
| 1 000 | Vector | 1.4767 s | 0.0005 s | 0.0001 s | 1.4773 s |
| 1 000 | Deque | 0.0050 s | 0.0006 s | 0.0001 s | 0.0058 s |
| 1 000 | List | 1.6105 s | 0.0002 s | 0.0394 s | 1.6500 s |
| |
| 10 000 | Vector | 0.0243 s | 0.0055 s | 0.0010 s | 0.0308 s |
| 10 000 | Deque | 0.0255 s | 0.0065 s | 0.0009 s | 0.0329 s |
| 10 000 | List | 0.0522 s | 0.0023 s | 0.0008 s | 0.0553 s |
| |
| 100 000 | Vector | 0.2627 s | 0.0723 s | 0.0160 s | 0.3510 s |
| 100 000 | Deque | 0.2631 s | 0.0846 s | 0.0130 s | 0.3607 s |
| 100 000 | List | 0.3248 s | 0.0558 s | 0.0225 s | 0.4031 s |
| |
| 1 000 000 | Vector | 2.6719 s | 0.9382 s | 0.2015 s | 3.8116 s |
| 1 000 000 | Deque | 2.6167 s | 1.0758 s | 0.1552 s | 3.8477 s |
| 1 000 000 | List | 3.0004 s | 0.9178 s | 0.3431 s | 4.2613 s |
| |
| 10 000 000 | Vector | 27.8593 s | 12.5252 s | 2.1647 s | 42.5492 s |
| 10 000 000 | Deque | 26.2060 s | 14.2441 s | 1.7180 s | 42.1680 s |
| 10 000 000 | List | 31.0290 s | 14.4062 s | 3.4994 s | 48.9346 s |
