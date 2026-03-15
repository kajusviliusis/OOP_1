



## Kompiuterio specifikacijos
- Procesorius: Intel Core i5-12450H, 8 branduoliai
- RAM: 16 GB
- SSD: 512 GB

## 2 Tyrimas su skirtingais konteineriais
| Studentų kiekis faile | Konteinerio tipas | Nuskaitymas | Rikiavimas | Skirstymas | Programos veikimas |
| --------- | ----------------- |-------------| ---------- | ---------- | ------------------ |
| 1 000 | Vector | 0.0050 s | 0.0006 s | 0.0004 s | 0.0061 s |
| 1 000 | Deque | 0.0074 s | 0.0014 s | 0.0003 s | 0.0092 s |
| 1 000 | List | 0.0061 s | 0.0002 s | 0.0002 s | 0.0064 s |
| |
| 10 000 | Vector | 0.0260 s | 0.0055 s | 0.0017 s | 0.0332 s |
| 10 000 | Deque | 0.0316 s | 0.0080 s | 0.0017 s | 0.0414 s |
| 10 000 | List | 0.0254 s | 0.0023 s | 0.0020 s | 0.0297 s |
| |
| 100 000 | Vector | 0.2669 s | 0.0706 s | 0.0242 s | 0.3617 s |
| 100 000 | Deque | 0.2947 s | 0.0919 s | 0.0213 s | 0.4079 s |
| 100 000 | List | 0.2711 s | 0.0423 s | 0.0265 s | 0.3399 s |
| |
| 1 000 000 | Vector | 2.6057 s | 0.9218 s | 0.2898 s | 3.8172 s |
| 1 000 000 | Deque | 2.8265 s | 1.1935 s | 0.2586 s | 4.2786 s |
| 1 000 000 | List | 2.5718 s | 0.8224 s | 0.2784 s | 3.6726 s |
| |
| 10 000 000 | Vector | 26.9236 s | 12.3930 s | 3.1271 s | 42.4437 s |
| 10 000 000 | Deque | 26.1272 s | 13.3469 s | 2.6759 s | 42.1500 s |
| 10 000 000 | List | 26.0462 s | 12.9069 s | 2.7769 s | 41.7300 s |