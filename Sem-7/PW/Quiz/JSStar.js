let totalReviews = 0;
let totalRating = 0;

function Rate(rating) {
  totalReviews++;
  totalRating += rating;

  document.getElementById("output").innerHTML = "Rating : " + rating + "/5";
  document.getElementById("total").innerHTML = "Total Review : " + totalReviews;

  const averageRating = (totalRating / totalReviews).toFixed(1);
  document.getElementById("rerata").innerHTML = "Rata-rata : " + averageRating;
}
