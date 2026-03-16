
// to do: programos aprasas, naudojimosi instrukcijos, strategijos aprasas ir strategiju rezultatai


## Kompiuterio specifikacijos
- Procesorius: Intel Core i5-12450H, 8 branduoliai
- RAM: 16 GB
- SSD: 512 GB

## 2 Tyrimas su skirtingais konteineriais
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