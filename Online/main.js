
try {
  var myframe = document.getElementById('myframe');
  var x = myframe.querySelectorAll('textarea');
  var i = 0;
  for (i = 0; i < x.length; i++) {
    if(x[i].name.startsWith('rad_1_')) {
      x[i].value = "I loved the way you explained the topic. It was very easy to understand. I would like to take more courses.";
    }else if(x[i].name.startsWith('rad_2_')) {
      x[i].value = "Course content was very good, but it has many topics to cover. which makes it difficult to complete.";
    }else{
      x[i].value  = "No comments"
    }

  }

  x = myframe.querySelectorAll('input[type="radio"]');
  for (i = 1; i < x.length; i++) {
    if (x[i].getAttribute('name') == 'check') {
      continue;
    }
    x[i].click();
  }

} catch (err) {
  console.log(err);
}
