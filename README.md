
// to do: programos aprasas, naudojimosi instrukcijos


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
| --------- | ----------------- |-------------| ---------- | ---------- | ------------------ |
| 1 000 | Vector | 0.0135 s | 0.0005 s | 0.0001 s | 0.0142 s |
| 1 000 | Deque | 0.0061 s | 0.0006 s | 0.0001 s | 0.0068 s |
| 1 000 | List | 0.0055 s | 0.0003 s | 0.0002 s | 0.0061 s |
| |
| 10 000 | Vector | 0.0417 s | 0.0058 s | 0.0022 s | 0.0497 s |
| 10 000 | Deque | 0.0298 s | 0.0069 s | 0.0013 s | 0.0380 s |
| 10 000 | List | 0.0272 s | 0.0028 s | 0.0021 s | 0.0321 s |
| |
| 100 000 | Vector | 0.2902 s | 0.0714 s | 0.0175 s | 0.3791 s |
| 100 000 | Deque | 0.2716 s | 0.0842 s | 0.0175 s | 0.3733 s |
| 100 000 | List | 0.2696 s | 0.0425 s | 0.0377 s | 0.3498 s |
| |
| 1 000 000 | Vector | 2.6557 s | 0.9046 s | 0.1980 s | 3.7583 s |
| 1 000 000 | Deque | 2.5693 s | 1.0795 s | 0.2107 s | 3.8595 s |
| 1 000 000 | List | 2.6213 s | 0.8303 s | 0.4212 s | 3.8728 s |
| |
| 10 000 000 | Vector | 27.6374 s | 12.4473 s | 2.2160 s | 42.3007 s |
| 10 000 000 | Deque | 25.9727 s | 14.0559 s | 2.3694 s | 42.3980 s |
| 10 000 000 | List | 26.6935 s | 12.8898 s | 4.3207 s | 43.9039 s |

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
