import yfinance as yf
import os
# pip install yfinance

companies = [
    'AAPL', 'MSFT', 'AMZN', 'GOOG', 'GOOGL', 'FB', 'TSLA', 'NVDA', 'JPM', 'JNJ', 'V', 'PYPL', 'DIS', 'ADBE', 'UNH',
    'HD', 'BAC', 'MA', 'CMCSA', 'XOM', 'NFLX', 'INTC', 'VZ', 'KO', 'T', 'PFE', 'MRK', 'PEP', 'CSCO', 'WMT', 'ABT',
    'CRM', 'ABBV', 'CVX', 'NKE', 'MCD', 'BMY', 'DHR', 'ACN', 'AVGO', 'TXN', 'COST', 'QCOM', 'MDT', 'NEE', 'WFC', 'HON',
    'UNP', 'PM', 'LIN', 'AMGN', 'SBUX', 'LLY', 'ORCL', 'UPS', 'LOW', 'IBM', 'AMD', 'CAT', 'BA', 'RTX', 'MMM', 'GE',
]

if not os.path.exists('CSV'):
    os.makedirs('CSV')

not_exist = []

for company in companies:
    data = yf.download(tickers=company, start="2010-01-01", end="2023-12-1")
    if not data.empty:
        data.to_csv(f'CSV/{company}.csv')
    else:
        not_exist.append(company)

print('Companies not found:')
print(not_exist)
