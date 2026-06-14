# NotinOOP 🛍️

Конзолно приложение за симулация на онлайн магазин за парфюми, разработено като курсов проект по **Обектно-ориентирано програмиране** към ФМИ, СУ „Св. Климент Охридски", специалност „Софтуерно инженерство", 2025–2026 г.

---

## Описание

**NotinOOP** симулира основните процеси на съвременна платформа за електронна търговия. Системата поддържа управление на потребители, каталог от парфюми, поръчки, наличности и различни видове намаления.

---

## Структура на проекта

```
📁 NotinOOP/ 
├── 📄 main.cpp 
├── 📁 Entities/          
│   ├── 📄 Fragrance.h / .cpp 
│   ├── 📄 Review.h / .cpp 
│   ├── 📄 Purchase.h / .cpp 
│   └── 📄 FragranceFamily.h 
├── 📁 Users/           
│   ├── 📄 User.h / .cpp 
│   ├── 📄 Buyer.h / .cpp 
│   └── 📄 Admin.h / .cpp 
├── 📁 Discounts/       
│   ├── 📄 Discount.h / .cpp 
│   ├── 📄 BonusDiscount.h / .cpp 
│   └── 📄 BrandDiscount.h / .cpp 
├── 📁 Commands/        
│   ├── 📄 Command.h / .cpp 
│   ├── 📄 RegisterCommand.h / .cpp 
│   ├── 📄 AddToCartCommand.h / .cpp 
│   └── 📄 ... (останалите команди) 
└── 📁 System/          
    └── 📄 NotinOOP.h / .cpp
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

## Команди

*Използвайте командата help, за да видите всички налични команди за текущия тип потребител.*

### Без логин
* `register <username> <password>` | `login <username> <password>` | `help` | `end`

### Купувач
* **Пазаруване:** `add-to-cart <name>` | `remove-from-cart <name>` | `view-cart` | `checkout`
* **Поръчки:** `view-purchases` | `view-bought` | `cancel <purchase-id>`
* **Любими & Ревюта:** `add-to-wishlist <name>` | `remove-from-wishlist <name>` | `make-review <name> <rating> <comment>` | `recommend`
* **Профил & Системни:** `add-to-balance <amount>` | `logout` | `help` | `end`

### Администратор
* **Магазин:** `create-fragrance <name> <brand> <price> <family> <quantity>` | `add-quantity <name> <quantity>`
* **Поръчки & Модерация:** `deliver <purchase-id>` | `remove-review <fragrance-id> <review-id>` | `block-user <username>`
* **Системни:** `logout` | `help` | `end`

---
## Ваучери (Автоматични)
*Издават се след успешна покупка и се прилагат сами при следващ `checkout`.*
* **`Discount`**: Процентно намаление
* **`BonusDiscount`**: Процентно намаление + фиксирана сума
* **`BrandDiscount`**: Процентно намаление за конкретна марка

---

## Статуси на поръчка
`PENDING` | `DELIVERED` | `CANCELED`

---

## Автоматично блокиране

Ако на даден потребител бъдат премахнати **7 или повече ревюта** от администратор, акаунтът му се блокира автоматично.

---
