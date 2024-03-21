import pandas as pd
from collections import Counter


# CSV dosyasını oku
data = pd.read_csv('/odev.csv')

# A ve B grupları için sonuçları saklamak üzere listeler oluştur
results_a = []
results_b = []

# Veri setlerini satır satır işle
for index, row in data.iterrows():
    # Satırdaki verileri al ve NaN değerleri at
    row_data = row.dropna()
    # Eğer satır boş değilse işleme devam et
    if len(row_data) > 0:
        # En çok tekrar eden sayı ve sayısını bul
        most_common_num, count = Counter(row_data).most_common(1)[0]
        # Oranı hesapla
        ratio = count / len(row_data)
    else:
        # Eğer satır boş ise oranı 0 olarak ayarla
        ratio = 0
    
    # A grubu için ilk 16 satırı işle
    if index < 16:
        results_a.append((index+1, ratio))
    # B grubu için son 6 satırı işle
    elif index >= data.shape[0] - 6:
        results_b.append((index+1, ratio))

# Sonuçları yazdır
print("A Grubu Sonuçları:")
for index, ratio in results_a:
    print(f"Veri Seti {index}: {ratio}")

print("\nB Grubu Sonuçları:")
for index, ratio in results_b:
    print(f"Veri Seti {index}: {ratio}")

# Tüm çıktıların ilk 9 rakamını al ve virgülleri ve baştaki sıfırı kaldır
def process_ratios(results):
    first_9_digits_list = []
    for index, ratio in results:
        first_9_digits = ''.join([c for c in str(ratio) if c.isdigit()])[:9].lstrip('0')
        first_9_digits_list.append(first_9_digits)
    return first_9_digits_list

print("\nA Grubu İlk 9 Rakamı:")
for digit in process_ratios(results_a):
    print(digit)

print("\nB Grubu İlk 9 Rakamı:")
for digit in process_ratios(results_b):
    print(digit)
