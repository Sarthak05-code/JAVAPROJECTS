const fetchData = async () => {
    const Data = await fetch('https://dummyjson.com/products')
    const res = await Data.json()
    const products = res.products

    const wrapper = document.querySelector('.cards-wrapper')

    
    for (let i = 0; i < products.length; ++i) {
        const card = document.createElement('div')
        card.classList.add('card-data')

        const imageRow = document.createElement('img')
        imageRow.src = products[i].images[0]
        imageRow.alt = products[i].title
        imageRow.classList.add('cardImage')
        card.appendChild(imageRow)

        const nameRow = document.createElement('p')
        nameRow.classList.add('cardName')
        nameRow.innerHTML = `${products[i].title}`
        card.appendChild(nameRow)

        const categoryRow = document.createElement('p')
        categoryRow.classList.add('cardCategory')
        categoryRow.innerHTML = `${products[i].category}`
        card.appendChild(categoryRow)

        const ratingRow = document.createElement('p')
        ratingRow.classList.add('cardRating')
        ratingRow.innerHTML = `${products[i].rating}`
        card.appendChild(ratingRow)

        wrapper.appendChild(card)
    }
}

fetchData()