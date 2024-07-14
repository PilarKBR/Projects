# Bahasa Indonesia
## Ringkasan Insight yang di Dapat
Untuk melihat detail notebook yang digunakan dapat diakses melalui [Link Berikut](https://colab.research.google.com/drive/1kC1dS0MDsBoOxX-HXtIWr1e7uJVTd_HS?usp=sharing)
Dikarenakan Github tidak bisa load file yang besar

- Klaster yang terbentuk dari penerapan K-means pada RFM Scores untuk dataset ini berjumlah 5 klaster
- Kategori Barang Fashion, Food & Drink, dan Transportasi menjadi primadona kebanyakan pengguna dalam transaksi pembelian kategori barang & jasa pada E-commerce ini
- Profiling Cluster
    - Bawah (Cluster 3): Rata-rata penggunanya merupakan Calon Pengguna yang Loyal dengan Total transaksi tergolong Rendah, namun Pengeluaran Paling Rendah dibanding golongan lain
    - Menengah ke Bawah (Cluster 4): Rata-rata penggunanya merupakan Calon Pengguna yang Loyal dengan Total transaksi tergolong Paling Rendah, namun Pengeluaran tergolong Rendah
    - Menengah (Cluster 0): Rata-rata penggunanya merupakan Calon Pengguna yang Loyal dengan Total transaksi dan Pengeluaran tergolong Sedang
    - Menengah ke Atas (Cluster 2): Frekuensi belanja mereka memang terbilang rendah, namun sekalinya mereka bertransaksi, nominal yang dikeluarkan dan Total transaksi yang mereka lakukan tergolong Tinggi
    - Atas (Cluster 1): Frekuensi belanja mereka memang terbilang rendah, namun sekalinya mereka bertransaksi, nominal yang dikeluarkan dan Total transaksi yang mereka lakukan merupakan yang paling tertinggi diantara golongan lain

## Tindakan yang Harus diambil untuk per Masing Klaster
- Bawah (Cluster 3):
Kebanyakan Prediksi Kategori Barang tiap Golongan Bawah (Cluster 3) pada notebook menunjukkan prediksi yang stabil, sehingga menawarkan promo dengan harga yang terjangkau untuk kategori barang lain merupakan tindakan yang tepat untuk Golongan Bawah.
- Menengah ke Bawah (Cluster 4):
Berikan promo (bisa berupa voucher diskon, cashback, dll) untuk kategori barang tertentu, yang disesuaikan dengan pembelian kategori barang yang pernah dibeli masing-masing pelanggan dalam 1 tahun terakhir.
- Menengah (Cluster 0):
Berikan rekomendasi barang yang dipersonalisasi berdasarkan riwayat transaksi mereka dan berikan promo-promo menarik pada kategori barang yang sering mereka beli.
- Menengah ke Atas (Cluster 2):
Jika kita telisik lagi, pergerakan grafik jumlah pengeluaran golongan menengah ke atas dalam satu bulan ini rata-rata stabil, namun range jumlah pengeluarannya akan selalu berbeda-beda tiap bulannya.
Hal ini diperkuat pada pergerakan grafik jumlah pengeluaran masing-masing kategori barang dan prediksinya dari golongan Menengah ke Atas ini sama seperti yang dijelaskan sebelumnya, sehingga pelanggan bergolongan Menengah ke Atas ini berpeluang besar merupakan pelanggan musiman.
Oleh karena itu, Tindakan yang tepat kepada pelanggan golongan menengah ke atas berupa pemberian rekomendasi dan promo-promo menarik pada kategori barang yang sedang musim/trend untuk 1 bulan ke depan
- Atas (Cluster 1):
Terapkan metode bundle untuk beberapa kategori barang dan/atau berikan pelayanan & benefit yang lebih dibanding Golongan lain

# English
## Summary of Insights
To see the details of the notebook used can be accessed through [The following link](https://colab.research.google.com/drive/1kC1dS0MDsBoOxX-HXtIWr1e7uJVTd_HS?usp=sharing)
Because Github cannot load large files

- Clusters formed from the application of K-means on RFM Scores for this dataset amounted to 5 clusters
- Categories of Goods Fashion, Food & Drink, and Transportation are the favorites of most users in purchasing transactions for goods & services categories in this E-commerce.
- Cluster Profiling
    - Bottom (Cluster 3): The average user is a Loyal Prospective User with a relatively Low Total transaction, but the Lowest Expenditure compared to other clusters
    - Middle to Lower (Cluster 4): The average user is a Loyal Prospective User with Total transactions classified as Lowest, but Spending is Low compared to other clusters
    - Middle (Cluster 0): The average user is a Loyal Prospective User with Total transactions and Expenses classified as Medium
    - Upper Middle (Cluster 2): Their shopping frequency is fairly low, but once they make a transaction, the amount spent and the total transactions they make are high
    - Upper (Cluster 1): Their shopping frequency is fairly low, but once they make a transaction, the amount spent and the total transaction they make are the highest among other groups.

## Actions to be taken for each Cluster
- Bottom (Cluster 3):
Most Item Category Predictions for each Lower Cluster (Cluster 3) on notebooks show stable predictions, so offering affordable promos on other item categories is an appropriate action for the Lower Cluster.
- Middle to Lower (Cluster 4):
Provide promos (can be in the form of discount vouchers, cashback, etc.) for certain categories of goods, which are tailored to the category of goods that each customer has purchased in the past 1 year.
- Middle (Cluster 0):
Provide personalized item recommendations based on their transaction history and provide attractive promos on the categories of goods they often buy.
- Upper middle class (Cluster 2):
If we look again, the movement of the graph of the amount of expenditure of the upper middle class in one month is on average stable, but the range of the amount of expenditure will always vary every month.
This is reinforced by the movement of the graph of the total expenditure of each category of goods and the prediction of the Upper Middle class is the same as described earlier, so this Upper Middle class customer is likely to be a seasonal customer.
Therefore, the right action for upper middle class customers is in the form of providing recommendations and attractive promos on the category of goods that are in season/trend for the next 1 month.
- Upper (Cluster 1):
Apply the bundle method for several categories of goods and/or provide more services & benefits than other groups.