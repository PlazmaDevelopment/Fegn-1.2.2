# Fegn 1.2.2

Fegn, Wholf dilinde entegrasyon ve veri yönetimi için kullanılan temel bir kütüphanedir.

## Özellikler

- Temel API entegrasyonu
- Basit veri yönetimi
- Temel olay yönetimi

## Kurulum

```wholf
fort import "Fegn-1.2.2"
```

## Kullanım Örnekleri

### API Entegrasyonu

```wholf
// API entegrasyonu
fegn Api {
    baseUrl: "https://api.example.com",
    headers: {
        "Content-Type": "application/json"
    }
}

// GET isteği
Api.get("/users")

// POST isteği
Api.post("/users", {
    name: "Ahmet",
    email: "ahmet@example.com"
})
```

### Veri Yönetimi

```wholf
// Veri depolama
fegn DataStore {
    users: []
}

// Veri ekleme
DataStore.addUser({
    id: 1,
    name: "Ahmet"
})
```

### Olay Yönetimi

```wholf
// Olay tanımlama
fegn Event {
    userAdded: (user) => {
        Console.log("Yeni kullanıcı eklendi: " + user.name)
    }
}

// Olay tetikleme
Event.trigger("userAdded", {
    id: 1,
    name: "Ahmet"
})
```

## Lisans

MIT License
