# NotinOOP 🛍️

Конзолно приложение за симулация на онлайн магазин за парфюми, разработено като курсов проект по **Обектно-ориентирано програмиране** към ФМИ, СУ „Св. Климент Охридски", специалност „Софтуерно инженерство", 2025–2026 г.

---

## 📋 Описание

**NotinOOP** симулира основните процеси на съвременна платформа за електронна търговия. Системата поддържа управление на потребители, каталог от парфюми, поръчки, наличности и различни видове намаления.

---

## 🏗️ Структура на проекта

```
📁 NotinOOP/
├── 📄main.cpp
├── 📁 System/
│   ├── NotinOOP.h
│   └── NotinOOP.cpp
├── 📁 Users/
│   ├── User.h / User.cpp
│   ├── Buyer.h / Buyer.cpp
│   ├── Admin.h / Admin.cpp
│   ├── Cart.h / Cart.cpp
│   └── Wishlist.h / Wishlist.cpp
├── 📁 Entities/
│   ├── Fragrance.h / Fragrance.cpp
│   ├── FragranceFamily.h
│   ├── Purchase.h / Purchase.cpp
│   └── Review.h / Review.cpp
├── 📁 Discounts/
│   ├── Discount.h / Discount.cpp
│   ├── BonusDiscount.h / BonusDiscount.cpp
│   └── BrandDiscount.h / BrandDiscount.cpp
└── 📁 Commands/
    ├── Command.h
    ├── CommandFactory.h / CommandFactory.cpp
    └── [всички команди].h / .cpp
```

---

## 👥 Видове потребители

### Администратор
При първоначално стартиране се създава автоматично с:
- **Потребителско име:** `admin`
- **Парола:** `admin123`

### Купувач
Регистриран потребител с количка, wishlist, баланс и ваучери за намаление.

---

## 💻 Команди

### Без логин
| Команда | Описание |
|---|---|
| `register <username> <password>` | Регистрация на нов купувач |
| `login <username> <password>` | Вход в системата |
| `help` | Показва достъпните команди |
| `end` | Записва данните и излиза |

### Купувач
| Команда | Описание |
|---|---|
| `add-to-balance <amount>` | Добавя сума към баланса |
| `add-to-cart <name>` | Добавя парфюм в количката |
| `remove-from-cart <name>` | Премахва парфюм от количката |
| `view-cart` | Показва съдържанието на количката |
| `add-to-wishlist <name>` | Добавя парфюм в любими |
| `remove-from-wishlist <name>` | Премахва парфюм от любими |
| `checkout` | Финализира покупката |
| `cancel <purchase-id>` | Отказва поръчка със статус PENDING |
| `view-purchases` | Показва всички поръчки |
| `view-bought` | Показва само доставените поръчки |
| `recommend` | Препоръчва 3 парфюма по предпочитания |
| `make-review <name> <rating> <comment>` | Оставя ревю за парфюм |
| `logout` | Изход от акаунта |
| `help` | Показва достъпните команди |
| `end` | Записва данните и излиза |

### Администратор
| Команда | Описание |
|---|---|
| `create-fragrance <name> <brand> <price> <family> <quantity>` | Добавя нов парфюм |
| `add-quantity <name> <quantity>` | Добавя наличност |
| `deliver <purchase-id>` | Маркира поръчка като доставена |
| `remove-review <fragrance-id> <review-id>` | Премахва ревю |
| `block-user <username>` | Блокира и изтрива потребител |
| `logout` | Изход от акаунта |
| `help` | Показва достъпните команди |
| `end` | Записва данните и излиза |

---

## 🧴 Категории парфюми (FragranceFamily)

| Стойност | Описание |
|---|---|
| `FLORAL` | Цветни нотки |
| `WOODY` | Дървесни нотки |
| `FRESH` | Свежи нотки |
| `ORIENTAL` | Ориенталски нотки |

---

## 🎟️ Видове ваучери

Ваучерите се раздават **автоматично** след всяка успешна покупка и се прилагат автоматично при следващ `checkout`.

| Тип | Описание |
|---|---|
| `Discount` | Процентно намаление |
| `BonusDiscount` | Процентно намаление + фиксирана сума |
| `BrandDiscount` | Процентно намаление за конкретна марка |

---

## 📦 Статуси на поръчка

| Статус | Описание |
|---|---|
| `PENDING` | Изчакваща обработка |
| `DELIVERED` | Доставена |
| `CANCELED` | Отказана |

---


## 📌 Примерна сесия

```
login admin admin123
create-fragrance Perfume1 CHANEL 120.00 FLORAL 10
logout

register ivan ivan123
login ivan ivan123
add-to-balance 500
add-to-cart Perfume1
checkout
make-review Perfume1 5 Amazing_scent
view-purchases
logout

end
```

---

## 🔒 Автоматично блокиране

Ако на даден потребител бъдат премахнати **7 или повече ревюта** от администратор, акаунтът му се блокира автоматично.

---
