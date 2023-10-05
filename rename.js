const fs = require('fs');

fs.readFile('submissions/info.json', 'utf8', (err, data) => {
  if (err) {
    console.error(err);
    return;
  }
  let submissions = JSON.parse(data);

  for(let pid of Object.keys(submissions)) {
    // console.log(pid + ' -> ' + submissions[pid].problem);
    let oldPath = 'submissions/' + pid + '.java';
    let newPath = 'submissions/' + submissions[pid].problem + '.java';
    fs.rename(oldPath, newPath, (err) => {
      if (err) {
        console.error(err);
        return;
      }
    });

    oldPath = 'submissions/' + pid + '.py';
    newPath = 'submissions/' + submissions[pid].problem + '.py'; 
    fs.rename(oldPath, newPath, (err) => {
      if (err) {
        console.error(err);
        return;
      }
    });

    oldPath = 'submissions/' + pid + '.cpp';
    newPath = 'submissions/' + submissions[pid].problem + '.cpp'; 
    fs.rename(oldPath, newPath, (err) => {
      if (err) {
        console.error(err);
        return;
      }
    });
  }
});