create database FinalIMDB
go

use FinalIMDB
go

create Table Actor(
id int  NOT NULL PRIMARY KEY,
[name] varchar(100),
bday date,
gender char
)
create table actorBio
(
	bio varchar(500),
	id int FOREIGN KEY REFERENCES Actor(id)
	CONSTRAINT pk_actorBio PRIMARY KEY (id)
)

create Table Movie(
id int  NOT NULL ,
rating float,
title varchar(200),
releasedate date,
Price float,
genreID int,
noOfUsersWhorated int,
CONSTRAINT pk_movie PRIMARY KEY (id)
)

create TABLE MoviePlot(
Movieid int FOREIGN KEY REFERENCES Movie(id),
plot varchar(500),
CONSTRAINT pk_movieplot PRIMARY KEY (Movieid)
)

create table MovieTrailerLink(
Movieid int FOREIGN KEY REFERENCES Movie(id),
trailer_link varchar(200),
CONSTRAINT pk_movietrailer PRIMARY KEY (Movieid)
)

create Table _Cast(
movie_id int FOREIGN KEY REFERENCES Movie(id),
actor_id int FOREIGN KEY REFERENCES Actor(id),
CONSTRAINT pk_cast PRIMARY KEY (actor_id,movie_id)
)

create Table Users(
id nvarchar(50),
email nvarchar(100) NOT NULL PRIMARY KEY
)

create table UserPassword(
userEmail nvarchar(100) FOREIGN KEY REFERENCES Users(email),
[password] varchar(100),
CONSTRAINT pk_userpassword PRIMARY KEY (userEmail)

)

create Table Watchlist(
userEmail nvarchar(100) FOREIGN KEY REFERENCES Users(email),
movie_id int FOREIGN KEY REFERENCES Movie(id),
CONSTRAINT pk_watchlist PRIMARY KEY (userEmail, movie_id)
)

create Table MoviesRent(
userEmail nvarchar(100) FOREIGN KEY REFERENCES Users(email),
movieID int FOREIGN KEY REFERENCES Movie(id),
RentDate Date,
DueDate Date,
CONSTRAINT pk_movieRent PRIMARY KEY (userEmail, movieID)
)

create table Genre
(
genreid int not Null primary key,
genre_name varchar(100)
)

 Alter Table Movie add constraint FKmovie foreign key (genreID) references Genre(genreid)

 INSERT INTO Genre(genreid,genre_name)
 Values(0,'Thriller'),
 (1,'Action'),
 (2,'Suspense'),
 (3,'Comedy'),
 (4,'Romantic'),
 (5,'Drama'),
 (6,'Musical'),
 (7,'Fantasy'),
 (8,'Sci-Fi'),
 (9,'Western'),
 (10,'Crime'),
 (11,'Historical')
 

 INSERT INTO Actor (id, [name], bday, gender)
Values
	(1, 'Claire Foy', '1984-4-16', 'F'),
	(2, 'Mike Epps', '1970-11-18', 'F'),
	(3, 'Orlando Bloom', '1977-1-13', 'M'),
	(4, 'Chris Elliott', '1960-5-31', 'M'),
	(5, 'Tom Hanks', '1956-7-9', 'M'),
	(6, 'Terry Crews', '1968-7-30', 'M'),
	(7, 'Jamie Lee Curtis', '1958-11-22', 'F'),
	(8, 'Bruce Willis', '1955-3-19', 'F'),
	(9, 'Saoirse Ronan', '1994-4-12', 'F'),
	(10, 'Joshua Leonard', '1975-6-17', 'F'),
	(11, 'Madison Wolfe', '2002-10-16', 'M'),
	(12, 'Claire Forlani', '1971-12-17', 'F'),
	(13, 'T.K. Carter', '1956-12-18', 'M'),
	(14, 'Bill Paxton', '1955-5-17', 'M'),
	(15, 'Anthony Hopkins', '1937-12-31', 'F'),
	(16, 'Mark Wahlberg', '1971-6-5', 'M'),
	(17, 'Jessica Brown Findlay', '1989-9-14', 'F'),
	(18, 'Bryan Barter', '1976-3-18', 'M'),
	(19, 'Christian Bale', '1974-1-30', 'M'),
	(20, 'Jeff Goldblum', '1952-10-22', 'M'),
	(21, 'Skyler Gisondo', '1996-7-22', 'M'),
	(22, 'Rutanya Alda', '1942-10-13', 'F'),
	(23, 'Steve Carell', '1962-8-16', 'F'),
	(24, 'Al Pacino', '1940-4-25', 'M'),
	(25, 'Christina Applegate', '1971-11-25', 'F'),
	(26, 'Jennifer Jason Leigh', '1962-2-5', 'M'),
	(27, 'Talulah Riley', '1985-9-26', 'F'),
	(28, 'Leonardo DiCaprio', '1974-11-11', 'M'),
	(29, 'Eddie Redmayne', '1982-1-6', 'F'),
	(30, 'Morgan Freeman', '1937-6-1', 'M'),
	(31, 'Tom Arnold', '1959-3-6', 'M'),
	(32, 'Ryan Gosling', '1980-11-12', 'M'),
	(33, 'Evangeline Lilly', '1979-8-3', 'F'),
	(34, 'Cloris Leachman', '1926-4-30', 'M'),
	(35, 'Kyle Gallner', '1986-10-22', 'F'),
	(36, 'Brad Pitt', '1963-12-18', 'M'),
	(37, 'Steven Bauer', '1956-12-2', 'M'),
	(38, 'Patrick Stewart', '1940-7-13', 'M'),
	(39, 'Ben Miller', '1966-2-24', 'M'),
	(40, 'Christoph Waltz', '1956-10-4', 'M'),
	(41, 'Imogen Poots', '1989-6-3', 'M'),
	(42, 'Joseph Gordon-Levitt', '1981-2-17', 'M'),
	(43, 'Aaron Ruell', '1976-6-23', 'M'),
	(44, 'Chuck Zito', '1953-3-1', 'M'),
	(45, 'Bill Murray', '1950-9-21', 'M'),
	(46, 'Keira Knightley', '1985-3-26', 'F'),
	(47, 'Brenda Blethyn', '1946-2-20', 'F'),
	(48, 'Jake Gyllenhaal', '1980-12-19', 'M'),
	(49, 'Sofia Boutella', '1982-4-3', 'F'),
	(50, 'Michael Douglas', '1944-9-25', 'M'),
	(51, 'Chris Hemsworth', '1983-8-11', 'M'),
	(52, 'Virginia Madsen', '1961-9-11', 'F'),
	(53, 'Michelle Pfeiffer', '1958-4-29', 'F'),
	(54, 'Kurt Russell', '1951-3-17', 'M'),
	(55, 'Aitana Sánchez-Gijón', '1968-11-5', 'F'),
	(56, 'Liam Hemsworth', '1990-1-13', 'M'),
	(57, 'Kevin Bacon', '1958-7-8', 'M'),
	(58, 'Alicia Vikander', '1988-10-3', 'F'),
	(59, 'Jennifer Lawrence', '1990-8-15', 'M'),
	(60, 'Chris Evans', '1981-6-13', 'M'),
	(61, 'Leslie Mann', '1972-3-26', 'F'),
	(62, 'Selma Blair', '1972-6-23', 'F'),
	(63, 'Claire Danes', '1979-4-12', 'F'),
	(64, 'Mathieu Amalric', '1965-10-25', 'M'),
	(65, 'Laura Dern', '1967-2-10', 'F'),
	(66, 'Rachel Weisz', '1970-3-7', 'M'),
	(67, 'Rooney Mara', '1985-4-17', 'F'),
	(68, 'Ice Cube', '1969-6-15', 'F'),
	(69, 'Julianne Moore', '1960-12-3', 'F'),
	(70, 'F. Murray Abraham', '1939-10-24', 'M'),
	(71, 'Luke Wilson', '1971-9-21', 'M'),
	(72, 'Wilford Brimley', '1934-9-27', 'M'),
	(73, 'Jon Gries', '1957-6-17', 'M'),
	(74, 'Emma Watson', '1990-4-15', 'F'),
	(75, 'Andrew Kevin Walker', '1964-8-14', 'M'),
	(76, 'Zoe Saldana', '1978-6-19', 'F'),
	(77, 'Ralph Fiennes', '1962-12-22', 'M'),
	(78, 'Michiel Huisman', '1981-7-18', 'M'),
	(79, 'Rowan Atkinson', '1955-1-6', 'M'),
	(80, 'Harrison Ford', '1942-7-13', 'M'),
	(81, 'Susan Sarandon', '1946-10-4', 'M'),
	(82, 'Andie MacDowell', '1958-4-21', 'F'),
	(83, 'Diane Keaton', '1946-1-5', 'F'),
	(84, 'Emmy Rossum', '1986-9-12', 'F'),
	(85, 'Rupert Grint', '1988-8-24', 'M'),
	(86, 'Hugo Weaving', '1960-4-4', 'M'),
	(87, 'Daniel Radcliffe', '1989-7-23', 'M'),
	(88, 'Dee Wallace', '1948-12-14', 'F'),
	(89, 'Dafne Keen', '2005-1-4', 'F'),
	(90, 'Idris Elba', '1972-9-6', 'M'),
	(91, 'Sam Elliott', '1944-8-9', 'M'),
	(92, 'Natalie Portman', '1981-6-9', 'F'),
	(93, 'Juliette Lewis', '1973-6-21', 'F'),
	(94, 'Sean Young', '1959-11-20', 'M'),
	(95, 'Sarah Paulson', '1974-12-17', 'F'),
	(96, 'Daniel Zacapa', '1951-7-19', 'M'),
	(97, 'Rosamund Pike', '1979-1-27', 'M'),
	(98, 'Ryan Reynolds', '1976-10-23', 'M'),
	(99, 'Bradley Cooper', '1975-1-5', 'F'),
	(100, 'Sam Neill', '1947-9-14', 'M'),
	(101, 'Josh Hutcherson', '1992-10-12', 'M'),
	(102, 'Rutger Hauer', '1944-1-23', 'M'),
	(103, 'Graham Verchere', '2002-2-4', 'M'),
	(104, 'Ed Helms', '1974-1-24', 'M'),
	(105, 'Rachel McAdams', '1978-11-17', 'M'),
	(106, 'Jesse Eisenberg', '1983-10-5', 'F'),
	(107, 'Wil Traval', '1980-7-9', 'M'),
	(108, 'Michael Shannon', '1974-8-7', 'M'),
	(109, 'Kristen Wiig', '1973-8-22', 'M'),
	(110, 'Ginnifer Goodwin', '1978-5-22', 'M'),
	(111, 'Maya Rudolph', '1972-7-27', 'F'),
	(112, 'Peter Coyote', '1941-10-10', 'M'),
	(113, 'Kasi Lemmons', '1961-2-24', 'F'),
	(114, 'Paul Rudd', '1969-4-6', 'M'),
	(115, 'Tom Courtenay', '1937-2-25', 'M'),
	(116, 'John Witherspoon', '1942-1-27', 'M'),
	(117, 'Henry Thomas', '1971-9-9', 'M'),
	(118, 'Randy Couture', '1963-6-22', 'F'),
	(119, 'Stephen Rea', '1946-10-31', 'M'),
	(120, 'Jodie Foster', '1962-11-19', 'F'),
	(121, 'Hayley Atwell', '1982-4-5', 'F'),
	(122, 'Hugh Jackman', '1968-10-12', 'M'),
	(123, 'Emily Blunt', '1983-2-23', 'F'),
	(124, 'Sebastian Stan', '1982-8-13', 'M'),
	(125, 'Jason Bateman', '1969-1-14', 'M'),
	(126, 'Reese Witherspoon', '1976-3-22', 'F'),
	(127, 'Johnny Depp', '1963-6-9', 'F'),
	(128, 'Michael Peña', '1976-1-13', 'M'),
	(129, 'Jamie Chung', '1983-4-10', 'F'),
	(130, 'Dennis Quaid', '1954-4-9', 'M'),
	(131, 'Tasha de Vasconcelos', '1966-8-15', 'F'),
	(132, 'Jon Heder', '1977-10-26', 'M'),
	(133, 'Jamie Foxx', '1967-12-13', 'F'),
	(134, 'Meryl Streep', '1949-6-22', 'M'),
	(135, 'Arnold Schwarzenegger', '1947-7-30', 'M'),
	(136, 'Geoffrey Rush', '1951-7-6', 'F')

Insert into actorBio
	(id, bio)
values
	(1, 'Claire Elizabeth Foy (born 16 April 1984) is an English actress. She studied acting at the Liverpool John Moores University and the Oxford School of Drama and made her screen debut in the pilot of the supernatural comedy series Being Human, in 2008. Following her professional stage debut at the Royal National Theatre, she played the title role in ...            '),
	(2, 'Mike Epps was born on November 18, 1970 in Indianapolis, Indiana, USA as Michael Elliot Epps. He is an actor and producer, known for Resident Evil: Apocalypse ) Resident Evil: Extinction )and The Hangover ) He has been married to Kyra Robinson since June 23, 2019. They have one child. He was previously married to Mechelle McCain.            '),
	(3, 'Orlando Jonathan Blanchard Bloom was born in Canterbury, Kent, England on January 13, 1977. His mother, Sonia Constance Josephine (Copeland), was born in Kolkata, India, to an English family then-resident there. The man he first knew as his father, Harry Bloom, was a legendary political activist who fought for civil rights in South Africa. But ...            '),
	(4, 'Chris Elliott was born on May 31, 1960 in New York City, New York, USA as Christopher Nash Elliott. He is an actor and writer, known for There s Something About Mary ) Groundhog Day )and Cabin Boy ) He has been married to Paula Niedert Elliott since March 8, 1986. They have two children.            '),
	(5, 'Thomas Jeffrey Hanks was born in Concord, California, to Janet Marylyn (Frager), a hospital worker, and Amos Mefford Hanks, an itinerant cook. His mother s family, originally surnamed "Fraga", was entirely Portuguese, while his father was of mostly English ancestry. Tom grew up in what he has called a "fractured" family. He moved around a great ...            '),
	(6, 'Terry Crews was born in Flint, Michigan, to Patricia and Terry Crews Sr. He earned an art excellence scholarship to attend Western Michigan University and also earned a full-ride athletic scholarship to play football. Crews was an All-Conference defensive end, and was a major contributor on the 1988 MAC champion WMU Broncos. His college success ...            '),
	(7, 'Jamie Lee Curtis was born on November 22, 1958 in Los Angeles, California, the daughter of legendary actors Janet Leigh and Tony Curtis. She got her big break at acting in 1978 when she won the role of Laurie Strode in Halloween ) After that, she became famous for roles in movies like Trading Places ) Perfect )and A Fish Called ...            '),
	(8, 'Actor and musician Bruce Willis is well known for playing wisecracking or hard-edged characters, often in spectacular action films. Collectively, he has appeared in films that have grossed in excess of $2.5 billion USD, placing him in the top ten stars in terms of box office receipts. Walter Bruce Willis was born on March 19, 1955, in ...            '),
	(9, 'Saoirse Una Ronan was born in The Bronx, New York City, New York, United States, to Irish parents, Monica Ronan (née Brennan) and Paul Ronan, an actor. When Saoirse was three, the family moved back to Dublin, Ireland. Saoirse grew up in Dublin and briefly in Co. Carlow before moving back to Dublin with her parents. Saoirse made her first TV ...            '),
	(10, 'A filmmaker, writer, and actor, Joshua Leonard has made an indelible mark on independent film and television throughout his career. He first came onto the scene in 1999 with lo-fi sensation The Blair Witch Project, perhaps one of the most talked about indie films of all time. As an actor, Leonard continues to work on projects that push the envelope...            '),
	(11, 'Madison Wolfe made her debut with the Will Ferrell-Zach Galifianakis comedy The Campaign and in the last two years has racked up a considerable amount of credits. While managing the workload of school, she simultaneously landed the role in The Campaign, and On the Road, directed by Walter Salles opposite Kristen Stewart and Sam Riley amongst other...            '),
	(12, 'Claire Forlani was born in the United Kingdom and grew up in London. Educated at Arts Educational School, she moved to the United States with her parents Pier Luigi and Barbara Forlani when she was 19 and began starring in films. Claire has had leading roles in such films as Meet Joe Black ) Basquiat ) The Rock ) Mystery Men )..            '),
	(13, 'T.K. Carter was raised just east of Los Angeles, California. He began his stand-up routine at age 12, and, by high school, appeared in Neil Simon s production of "The Odd Couple." He began his professional stand-up routine at the Comedy Store in Los Angeles and has also worked at the Improvisation Cafe and Ye Little Club. His first role was in an ...            '),
	(14, 'Bill Paxton was born on May 17, 1955 in Fort Worth, Texas. He was the son of Mary Lou (Gray) and John Lane Paxton, a businessman and actor (as John Paxton). Bill moved to Los Angeles, California at age eighteen, where he found work in the film industry as a set dresser for Roger Corman s New World Pictures. He made his film debut in the Corman ...            '),
	(15, 'Anthony Hopkins was born on December 31, 1937, in Margam, Wales, to Muriel Anne (Yeats) and Richard Arthur Hopkins, a baker. His parents were both of half Welsh and half English descent. Influenced by Richard Burton, he decided to study at College of Music and Drama and graduated in 1957. In 1965, he moved to London and joined the National Theatre...            '),
	(16, 'American actor Mark Wahlberg is one of a handful of respected entertainers who successfully made the transition from teen pop idol to acclaimed actor. A Best Supporting Actor Oscar nominee for The Departed )who went on to receive positive critical reviews for his performance in The Fighter ) Wahlberg also is a solid comedy actor, ...            '),
	(17, 'Jessica Brown Findlay is an English actress. She is known for Emelia Conan-Doyle in the British comedy-drama Albatross ) Winter s Tale ) This Beautiful Fantastic )and Lady Sybil Crawley in ITV s Downton Abbey ) She also starred in the TV series Misfits )and mini-series Labyrinth ) In 2011, she starred in the ...            '),
	(18, 'Bryan Barter was born on March 18, 1976 in Ann Arbor, Michigan, USA. He is an actor, known for The Social Network ) Arn: Tempelriddaren )and Helium Man )            '),
	(19, 'Christian Charles Philip Bale was born in Pembrokeshire, Wales, UK on January 30, 1974, to English parents Jennifer "Jenny" (James) and David Bale. His mother was a circus performer and his father, who was born in South Africa, was a commercial pilot. The family lived in different countries throughout Bale s childhood, including England, Portugal,...            '),
	(20, 'Jeffrey Lynn Goldblum was born October 22, 1952 in Pittsburgh, Pennsylvania, one of four children of Shirley (Temeles), a radio broadcaster who also ran an appliances firm, and Harold L. Goldblum, a doctor. His father was of Russian Jewish descent and his mother was of Austrian Jewish ancestry. Goldblum began his career on the New York stage after ...            '),
	(21, 'Skyler Gisondo was born on July 22, 1996 in Palm Beach County, Florida, USA. He is an actor, known for Vacation ) Night at the Museum: Secret of the Tomb )and The Amazing Spider-Man )            '),
	(22, 'Rutanya Alda was born on October 13, 1942 in Riga, Latvia as Rutanya Skrastina. She is known for her work on The Deer Hunter ) Mommie Dearest )and Amityville II: The Possession ) She was previously married to Richard Bright.            '),
	(23, 'Steve Carell, one of America s most versatile comics, was born Steven John Carell on August 16, 1962, in Concord, Massachusetts. He is the son of Harriet Theresa (Koch), a psychiatric nurse, and Edwin A. Carell, an electrical engineer. His mother was of Polish descent and his father of Italian and German ancestry (Steve s grandfather had changed ...            '),
	(24, 'Alfredo James "Al"  Pacino established himself as a film actor during one of cinema s most vibrant decades, the 1970s, and has become an enduring and iconic figure in the world of American movies. He was born April 25, 1940 in Manhattan, New York City, to Italian-American parents, Rose (nee Gerardi) and Sal Pacino. They divorced when he was young. ...            '),
	(25, 'Christina Applegate was born in Hollywood, Los Angeles, California, to record producer/executive Robert William Applegate and singer-actress Nancy Priddy. Her parents split-up shortly after her birth. She has two half-siblings from her father s re-marriage - Alisa (b. 10 October 1977) & Kyle (b. 15 July 1981). Alisa and Christina are best friends ...            '),
	(26, 'Jennifer Jason Leigh was born Jennifer Lee Morrow in Los Angeles, California, the daughter of writer Barbara Turner and actor Vic Morrow. Her father was of Russian Jewish descent and her mother was of Austrian Jewish ancestry. She is the sister of Carrie Ann Morrow and half-sister of actress Mina Badie. Jennifer s parents divorced when she was two....            '),
	(27, 'Talulah Riley is an English actress. She has appeared in films such as Pride & Prejudice ) St. Trinian s ) The Boat That Rocked )and Inception ) She made her stage debut in The Philadelphia Story at the Old Vic in 2005. Her television credits include episodes of Poirot (Poirot: Five Little Pigs ), Marple (Agatha ...            '),
	(28, 'Few actors in the world have had a career quite as diverse as Leonardo DiCaprio s. DiCaprio has gone from relatively humble beginnings, as a supporting cast member of the sitcom Growing Pains )and low budget horror movies, such as Critters 3 ) to a major teenage heartthrob in the 1990s, as the hunky lead actor in movies such as Romeo +...            '),
	(29, 'British actor Eddie Redmayne won the Academy Award for Best Actor (for The Theory of Everything ). Edward John David Redmayne was born and raised in London, England, the son of Patricia (Burke) and Richard Charles Tunstall Redmayne, a businessman. His great-grandfather was Sir Richard Augustine Studdert Redmayne, a noted civil and mining ...            '),
	(30, 'With an authoritative voice and calm demeanor, this ever popular American actor has grown into one of the most respected figures in modern US cinema. Morgan was born on June 1, 1937 in Memphis, Tennessee, to Mayme Edna (Revere), a teacher, and Morgan Porterfield Freeman, a barber. The young Freeman attended Los Angeles City College before serving ...            '),
	(31, 'Tom Arnold was born in Ottumwa, Iowa, to Linda (Graham) and Jack Arnold. After his parents divorced, he was raised by his father. In 1983, he got his first taste of stand-up comedy when he performed at open microphone nights at the University of Iowa. Tom s comedy career had its ups and downs over the next several years until 1988, when he entered...            '),
	(32, 'Canadian actor Ryan Gosling is the first person born in the 1980s to have been nominated for the Best Actor Oscar (for Half Nelson ). He was born Ryan Thomas Gosling on November 12, 1980, in London, Ontario, Canada. He is the son of Donna (Wilson), a secretary, and Thomas Ray Gosling, a traveling salesman. Ryan was the second of their two ...            '),
	(33, 'Evangeline Lilly, born in Fort Saskatchewan, Alberta, in 1979, was discovered on the streets of Kelowna, British Columbia, by the famous Ford modeling agency. Although she initially decided to pass on a modeling career, she went ahead and signed with Ford anyway, to help pay for her University of British Columbia tuition and expenses.            '),
	(34, 'The legendary actress set a record when at age 82, she appeared on Dancing with the Stars ) Cloris Leachman was born on April 30, 1926 in Des Moines, Iowa to Berkeley Claiborne "Buck" Leachman and the former Cloris Wallace. Her father s family owned a lumber company, Leachman Lumber Co. She is of Czech (from her maternal grandmother) and ...            '),
	(35, 'Kyle Gallner was born in West Chester, Pennsylvania. He started his career by following his sister along to one of her auditions. Perhaps best know for his role as Cassidy "Beaver" Casablancas on the CW s lone hit series, Veronica Mars ) actor Kyle Gallner had been appearing in films and on television since his early adolescence. Born on Oct....            '),
	(36, 'An actor and producer known as much for his versatility as he is for his handsome face, Golden Globe-winner Brad Pitt s most widely recognized role may be Tyler Durden in Fight Club ) However, his portrayals of Billy Beane in Moneyball ) and Rusty Ryan in the remake of Ocean s Eleven )and its sequels, also loom large in his ...            '),
	(37, 'Steven Bauer was born on December 2, 1956 in Havana, Cuba as Esteban Ernesto Echevarria. He is an actor and producer, known for Scarface ) Traffic )and Primal Fear )            '),
	(38, 'Sir Patrick Stewart was born in Mirfield, Yorkshire, England, to Gladys (Barrowclough), a textile worker and weaver, and Alfred Stewart, who was in the army. He was a member of various local drama groups from about age 12. He left school at age 15 to work as a junior reporter on a local paper,  he quit when his editor told him he was spending too ...            '),
	(39, 'Halfway through a PhD in physics at Cambridge University, Ben met Alexander Armstrong (who was also studying there) in 1992. Instead of finishing his PhD, Ben chose to scrap science for comedy and started playing at the Comedy Club Footlights, Cambridge. After four years of touring pubs and underground comedy clubs, the pair appeared on  Saturday ...            '),
	(40, 'Christoph Waltz is an Austrian-German actor. He is known for his work with American filmmaker Quentin Tarantino, receiving acclaim for portraying SS-Standartenführer Hans Landa in Inglourious Basterds )and bounty hunter Dr. King Schultz in Django Unchained ) For each performance, he won an Academy Award, a BAFTA Award, and a Golden ...            '),
	(41, 'British actress Imogen Poots was born in Hammersmith, London, England, the daughter of English-born Fiona (Goodall), a journalist, and Trevor Poots, a Northern Ireland-born television producer. She was educated at Bute House Preparatory School for Girls, Queen s Gate School for Girls and Latymer Upper School, all in London. When she was a teenager...            '),
	(42, 'Joseph Gordon-Levitt has completed production on the untitled Henry Joost/Ariel Schulman sci-fi film for Netflix in which he stars opposite Jamie Foxx and on the independent thriller, 7500, written and directed by Patrick Vollarth. Among his other projects, he is in development on a variety of feature films including Fraggle Rock. Gordon-Levitt s ...            '),
	(43, 'Aaron Ruell was born on June 23, 1976 in Fresno, California, USA as Derek Aaron Ruell. He is a director and actor, known for Napoleon Dynamite ) Everything s Gone Green )and Mary ) He is married to Yuka Ruell.            '),
	(44, 'Chuck Zito was born on March 1, 1953 in The Bronx, New York City, New York, USA as Charles Zito Jr. He is known for his work on Sons of Anarchy ) Oz )and Homefront )            '),
	(45, 'Bill Murray is an American actor, comedian, and writer. The fifth of nine children, he was born William James Murray in Wilmette, Illinois, to Lucille (Collins), a mailroom clerk, and Edward Joseph Murray II, who sold lumber. He is of Irish descent. Among his siblings are actors Brian Doyle-Murray, Joel Murray, and John Murray. He and most of his ...            '),
	(46, 'Keira Christina Knightley was born March 26, 1985 in the South West Greater London suburb of Richmond. She is the daughter of actor Will Knightley and actress turned playwright Sharman Macdonald. An older brother, Caleb Knightley, was born in 1979. Her father is English, while her Scottish-born mother is of Scottish and Welsh origin. Brought up ...            '),
	(47, 'After twenty years of hard work on stage and both television and film, there are not many other actresses who deserved the success, recognition and stardom which Brenda Blethyn has now achieved. Born in 1946 in Ramsgate, Kent, England, she started her career at British Rail in the 1960s. Saving money during her time there, she took a risk and ...            '),
	(48, 'Jacob Benjamin Gyllenhaal was born in Los Angeles, California, to producer/screenwriter Naomi Foner (née Achs) and director Stephen Gyllenhaal. He is the brother of actress Maggie Gyllenhaal, who played his sister in Donnie Darko ) His godmother is actress Jamie Lee Curtis. His mother is from a Jewish family, and his father s ancestry ...            '),
	(49, 'Sofia Boutella is an Algerian actress, dancer and model. She was born in the Bab El Oued district of Algiers in Algeria, the daughter of composer and jazz musician Safy Boutella, and an architect mother. She started classical dance education when she was five years old. In 1992, at age 10, she left Algeria with her family and moved to France, ...            '),
	(50, 'An actor with over forty years of experience in theatre, film, and television, Michael Douglas branched out into independent feature production in 1975 with the Academy Award-winning One Flew Over the Cuckoo s Nest ) Since then, as a producer and as an actor-producer, he has shown an uncanny knack for choosing projects that reflect changing ...            '),
	(51, 'Chris Hemsworth was born in Melbourne, Australia, to Leonie (van Os), a teacher of English, and Craig Hemsworth, a social-services counselor. His brothers are actors Liam Hemsworth and Luke Hemsworth. He is of Dutch (from his immigrant maternal grandfather), Irish, English, Scottish, and German ancestry. His uncle, by marriage, was Rod Ansell, the...            '),
	(52, 'One of the hottest stars of the mid-1980s, Virginia Madsen has since played a variety of roles that have cemented her reputation as a fantastic actress who can adapt to any part. Virginia was born in Chicago, Illinois, and belongs to an acting family -- with her brother, Michael Madsen, also an actor, and her mother, Elaine Madsen (née Melson), an ...            '),
	(53, 'Michelle Pfeiffer was born in Santa Ana, California, to Donna Jean (Taverna) and Richard Pfeiffer, a heating and air-conditioning contractor. She has an older brother and two younger sisters - Dedee Pfeiffer and Lori Pfeiffer, who both dabbled in acting and modeling but decided against making it their life s work. Her parents were both originally ...            '),
	(54, 'Kurt Russell was born Kurt Vogel Russell in Springfield, Massachusetts, to Louise Julia (Crone), a dancer, and actor Bing Russell (Neil Oliver Russell). He is of English, German, Scottish and Irish descent. His first roles were as a child on television series, including a lead role on the Western series The Travels of Jaimie McPheeters ) ...            '),
	(55, 'Aitana Sánchez-Gijón was born on November 5, 1968 in Rome, Lazio, Italy as Aitana Sánchez-Gijón de Angelis. She is an actress, known for The Machinist ) A Walk in the Clouds )and Boca a boca ) She has been married to Papin Luccadane since September 2002. They have two children.            '),
	(56, 'Liam Hemsworth was born on January 13, 1990, in Melbourne, Australia, and is the younger brother of actors Chris Hemsworth and Luke Hemsworth. He is the son of Leonie (van Os), a teacher of English, and Craig Hemsworth, a social-services counselor. He is of Dutch (from his immigrant maternal grandfather), Irish, English, Scottish, and German ...            '),
	(57, 'Kevin Norwood Bacon was born on July 8, 1958 in Philadelphia, Pennsylvania, to Ruth Hilda (Holmes), an elementary school teacher, and Edmund Norwood Bacon, a prominent architect who was on the cover of Time Magazine in November 1964. Kevin s early training as an actor came from The Manning Street. His debut as the strict Chip Diller in National ...            '),
	(58, 'Alicia Vikander is a Swedish actress, dancer and producer. She was born and raised in Gothenburg, Västra Götalands län, Sweden, to Maria Fahl-Vikander, an actress of stage and screen, and Svante Vikander, a psychiatrist. She is of Swedish and one quarter Finnish descent. Alicia began acting as a child in minor stage productions at The Göteborg ...            '),
	(59, 'Was the highest-paid actress in the world in 2015 and 2016. With her films grossing over $5.5 billion worldwide, Jennifer Lawrence is often cited as the most successful actor of her generation. She is also thus far the only person born in the 1990s to have won an acting Oscar. Jennifer Shrader Lawrence was born August 15, 1990 in Louisville, ...            '),
	(60, 'Christopher Robert Evans began his acting career in typical fashion: performing in school productions and community theatre. He was born in Boston, Massachusetts, the son of Lisa (Capuano), who worked at the Concord Youth Theatre, and G. Robert Evans III, a dentist. His uncle is congressman Mike Capuano. Chris s father is of half German and half ...            '),
	(61, 'Leslie Jean Mann was born in San Francisco, California. She was raised in Newport Beach, California by her mother, Janet Ann Ayres. At the age of seventeen, she launched her career, appearing in various TV commercials. Her screen break came when she was cast as Nurse Mary in the short-lived Birdland ) Further TV and film roles followed, ...            '),
	(62, 'One of our most exciting and versatile actresses, Selma Blair first gained attention for her performance in Cruel Intentions ) a youthful retelling of the classic novel "Les Liaisons Dangereuses". Selma was born in Southfield, Michigan, to Molly Ann (Cooke), a judge, and Elliot I. Beitner, a lawyer. She had a Jewish upbringing. After ...            '),
	(63, 'New Yorker Claire Catherine Danes was born in Manhattan, the daughter of Carla (Hall), a day-care provider and artist, and Christopher Danes, a computer consultant and photographer. She has an older brother, Asa. Her paternal grandfather, Gibson Andrew Danes, was a Dean of the Yale School of Art and Architecture. She is of mostly German and ...            '),
	(64, 'Mathieu Amalric was born on October 25, 1965 in Neuilly-sur-Seine, Hauts-de-Seine, France. He is an actor and director, known for Le scaphandre et le papillon ) The Grand Budapest Hotel )and Munich )            '),
	(65, 'Laura Dern was born on February 10, 1967 in Los Angeles, the daughter of actors Bruce Dern and Diane Ladd. Dern was exposed to movie sets and the movie industry from infancy, and obtained several bit parts as a child. Her parents divorced when Dern was two and Dern lost contact with her father for several years as a result. Her parents  background ...            '),
	(66, 'Rachel Hannah Weisz was born on 7 March, 1970, in London, U.K., to Edith Ruth (Teich), a psychoanalyst, and George Weisz, an inventor. Her parents both came to England around 1938. Her father is a Hungarian Jewish immigrant, and her mother, from Vienna, was of Italian and Austrian Jewish heritage. Rachel has a sister, Minnie, a curator and ...            '),
	(67, 'Actress and philanthropist Rooney Mara was born on April 17, 1985 in Bedford, New York. She made her screen debut in the slasher film Urban Legends: Bloody Mary ) went on to have a supporting role in the independent coming-of-age drama Tanner Hall ) and has since starred in the horror remake A Nightmare on Elm Street ) the ...            '),
	(68, 'Ice Cube was born in South Central Los Angeles, to Doris (Benjamin), a custodian and hospital clerk, and Hosea Jackson, a UCLA groundskeeper. He first came to public notice as a singer and songwriter with the controversial and influential band N.W.A. His compositions with that group included many of the classic cuts from their debut LP "Straight ...            '),
	(69, 'Julianne Moore was born Julie Anne Smith in Fort Bragg, North Carolina on December 3, 1960, the daughter of Anne (Love), a social worker, and Peter Moore Smith, a paratrooper, colonel, and later military judge. Her mother moved to the U.S. in 1951, from Greenock, Scotland. Her father, from Burlington, New Jersey, has German, Irish, Welsh, ...            '),
	(70, 'Academy Award-winning actor F. Murray Abraham was born on October 24, 1939 in Pittsburgh, Pennsylvania and raised in El Paso, Texas. His father, Frederick Abraham, was from an Assyrian Christian (Antiochian) family, from Syria. His mother, Josephine (Stello) Abraham, was the daughter of Italian immigrants. Born with the first name "Murray", he ...            '),
	(71, 'Handsome Texan Luke Cunningham Wilson was born in Dallas in 1971, to Irish-American parents originally from Massachusetts. The son of Laura (Cunningham), a photographer, and Robert Andrew Wilson, an advertising executive, he was raised with two brothers, Owen Wilson (the middle one) and Andrew Wilson (the eldest one). The three would all go on to ...            '),
	(72, 'Wilford Brimley was born on September 27, 1934 in Salt Lake City, Utah, USA as Anthony Wilford Brimley. He is known for his work on Cocoon ) The Natural )and The Thing ) He has been married to Beverly Berry since October 31, 2007. He was previously married to Lynne Brimley.            '),
	(73, 'Jon Gries was born on June 17, 1957 in Glendale, California, USA as Jonathan Francis Gries. He is an actor, known for Napoleon Dynamite ) Men in Black )and The Rundown )            '),
	(74, 'Emma Charlotte Duerre Watson was born in Paris, France, to English parents, Jacqueline Luesby and Chris Watson, both lawyers. She moved to Oxfordshire when she was five, where she attended the Dragon School. From the age of six, Emma knew that she wanted to be an actress and, for a number of years, she trained at the Oxford branch of Stagecoach ...            '),
	(75, 'Andrew Kevin Walker was born on August 14, 1964 in Altoona, Pennsylvania, USA. He is a writer and actor, known for Se7en ) Sleepy Hollow )and 8MM )            '),
	(76, 'Zoe Saldana was born on June 19, 1978 in Passaic, New Jersey, to Asalia Nazario and Aridio Saldaña. Her father was Dominican and her mother is Puerto Rican. She was raised in Queens, New York. When she was 10 years old, she and her family moved to the Dominican Republic, where they would live for the next seven years. While living there, Zoe ...            '),
	(77, 'Actor Ralph Nathaniel Twisleton-Wykeham-Fiennes was born on December 22, 1962 in Suffolk, England, to Jennifer Anne Mary Alleyne (Lash), a novelist, and Mark Fiennes, a photographer. He is the eldest of six children. Four of his siblings are also in the arts: Martha Fiennes, a director,  Magnus Fiennes, a musician,  Sophie Fiennes, a producer,  and ...            '),
	(78, 'Huisman was born on July 18, 1981 in Amstelveen, Noord-Holland, which is near Amsterdam, the Netherlands. Before Game of Thrones ) Huisman had a role in Paul Verhoeven s acclaimed Zwartboek ) and he played Rudolf Nureyev in the BBC TV movie Margot )about prima ballerina Margot Fonteyn. Before he became ubiquitous on television, ...            '),
	(79, 'Rowan Sebastian Atkinson was born on 6 January, 1955, in Consett, Co. Durham, UK, to Ella May (Bainbridge) and Eric Atkinson. His father owned a farm, where Rowan grew up with his two older brothers, Rupert and Rodney. He attended Newcastle University and Oxford University where he earned degrees in electrical engineering. During that time, he met...            '),
	(80, 'Harrison Ford was born on July 13, 1942 in Chicago, Illinois, to Dorothy (Nidelman), a radio actress, and Christopher Ford (born John William Ford), an actor turned advertising executive. His father was of Irish and German ancestry, while his maternal grandparents were Jewish emigrants from Minsk, Belarus. Harrison was a lackluster student at ...            '),
	(81, 'Susan Sarandon was born Susan Abigail Tomalin in New York City, NY, to homemaker Lenora Marie (Criscione) and Phillip Leslie Tomalin, an advertising executive. She is of Italian descent on her mother s side and English, Irish, Welsh, and German on her father s. After the 1968 Democratic convention there was a casting call for a film with several ...            '),
	(82, 'Andie MacDowell was born Rosalie Anderson MacDowell on April 21, 1958 in Gaffney, South Carolina, to Pauline Johnston (Oswald), a music teacher, and Marion St. Pierre MacDowell, a lumber executive. She was enrolled at Winthrop College located in Rock Hill, South Carolina. Initially discovered by a rep from Wilhelmina Models while on a trip to Los ...            '),
	(83, 'Diane Keaton was born Diane Hall in Los Angeles, California, to Dorothy Deanne (Keaton), an amateur photographer, and John Newton Ignatius "Jack" Hall, a civil engineer and real estate broker. She studied Drama at Santa Ana College, before dropping out in favor of the Neighborhood Playhouse in New York. After appearing in summer stock for several ...            '),
	(84, 'It would seem that 2004, the year of her 18th birthday, will be remembered as pivotal for Emmy Rossum due to her appearance in two very different films, The Day After Tomorrow )and The Phantom of the Opera ) Emmy s performance in the latter film gained her a Golden Globe nomination. Emmanuelle Grey Rossum was born in New York City, ...            '),
	(85, 'Rupert Alexander Lloyd Grint was born in Harlow, Essex, England, the elder son of Joanne (Parsons) and Nigel Grint, who dealt in memorabilia. The first of 5 children, Rupert has one brother and 3 sisters. His brother James was born when Rupert was a year old, Georgina and Samantha were born in 1993 and 1996 respectively, and last, but not least, ...            '),
	(86, 'Hugo Wallace Weaving was born on April 4, 1960 in Nigeria, to English parents Anne (Lennard), a tour guide and teacher, and Wallace Weaving, a seismologist. Hugo has an older brother, Simon, and a younger sister, Anna, who both also live and work in Australia. During his early childhood, the Weaving family spent most of their time traveling ...            '),
	(87, 'Daniel Jacob Radcliffe was born on July 23, 1989 in Fulham, London, England, to casting agent Marcia Gresham (née Jacobson) and literary agent Alan Radcliffe. His father is from a Northern Irish Protestant background, while his mother was born in South Africa, to a Jewish family (from Lithuania, Poland, Russia, and Germany). Daniel began ...            '),
	(88, 'This attractive, happy go lucky blonde actress, educated at the University of Kansas and a former ballet soloist, first broke into both TV and cinema screens in the mid 1970s and through her appearances in several well remembered horror and sci-fi films, and Dee quickly gained a cult following among the fantasy film fans. Poor Dee always seemed to...            '),
	(89, 'Dafne Keen Fernández is a British and Spanish actress who played the role of Ana "Ani" Cruz Oliver in the television series The Refugees, and the mutant Laura Kinney / X-23 in the 2017 film Logan. She is the daughter of British actor Will Keen, and Spanish actress, theatre director and writer María Fernández Ache. Her paternal great-grandfather was...            '),
	(90, 'An only child, Idrissa Akuna Elba was born and raised in London, England. His father, Winston, is from Sierra Leone and worked at Ford Dagenham,  his mother, Eve, is from Ghana and had a clerical duty. Idris attended school in Canning Town, where he first became involved in acting, before he dropped out. He gained a place in the National Youth ...            '),
	(91, 'Tall, thin, wiry Sam Elliott is the classic picture of the American cowboy. Elliott began his acting career on the stage and his film debut was in Butch Cassidy and the Sundance Kid ) Although his future wife, Katharine Ross co-starred in the film, the two did not meet until they filmed The Legacy )Together. Over the years there would ...            '),
	(92, 'Natalie Portman is the first person born in the 1980s to have won the Academy Award for Best Actress (for Black Swan ). Natalie was born Natalie Hershlag on June 9, 1981, in Jerusalem, Israel. She is the only child of Avner Hershlag, a Israeli-born doctor, and Shelley Stevens, an American-born artist (from Cincinnati, Ohio), who also acts as ...            '),
	(93, 'Juliette Lewis has been recognized as one of Hollywood s most talented and versatile actors of her generation since she first stunned audiences and critics alike with her Oscar-nominated performance as "Danielle Bowden" in Cape Fear ) To date, she has worked with some of the most revered directors in the industry, including Martin Scorsese, ...            '),
	(94, 'Mary Sean Young was born on November 20, 1959 in Louisville, Kentucky. She is the daughter of Lee Guthrie (née Mary Lee Kane), an Emmy-nominated producer, screenwriter, public relations executive, and journalist, and Donald Young, Jr., an Emmy award winning television news producer and journalist. She has Irish, English, and Swiss-German ancestry....            '),
	(95, 'Sarah Paulson was born on December 17, 1974 in Tampa, Florida, to Catharine Gordon (Dolcater) and Douglas Lyle Paulson II. She spent most of her early years in New York and Maine, before settling in Manhattan to attend the American Academy of Dramatic Arts and the High School for Performing Arts. Although she made her Broadway debut in "The Sisters...            '),
	(96, 'Honduran-born Daniel Zacapa has established himself as one of the most effective character actors working. His varied and diverse film roles include Se7en ) Confessions of a Dangerous Mind )  The Mexican ,  The Gene Generation , and  Phenomenon , sharing the screen with such actors as  Jack Lemmon , Walter Matthau, Morgan Freeman, Brad...            '),
	(97, 'Born on January 27, 1979 in London, England, actress Rosamund Mary Elizabeth Pike is the only child of a classical violinist mother, Caroline (Friend), and an opera singer father, Julian Pike. Due to her parents  work, she spent her early childhood traveling around Europe. Pike attended Badminton School in Bristol, England and began acting at the ...            '),
	(98, 'Ryan Rodney Reynolds was born on October 23, 1976 in Vancouver, British Columbia, Canada, the youngest of four children. His father, James Chester Reynolds, was a food wholesaler, and his mother, Tamara Lee "Tammy" (Stewart), worked as a retail-store saleswoman. He has Irish and Scottish ancestry. Between 1991-93, Ryan appeared in Hillside )...            '),
	(99, 'Bradley Charles Cooper was born on January 5, 1975 in Philadelphia, Pennsylvania. His mother, Gloria (Campano), is of Italian descent, and worked for a local NBC station. His father, Charles John Cooper, who was of Irish descent, was a stockbroker. Immediately after Bradley graduated from the Honors English program at Georgetown University in 1997...            '),
	(100, 'Sam Neill was born in Omagh, Co. Tyrone, Northern Ireland, to army parents, an English-born mother, Priscilla Beatrice (Ingham), and a New Zealand-born father, Dermot Neill. His family moved to the South Island of New Zealand in 1954. He went to boarding schools and then attended the universities at Canterbury and Victoria. He has a BA in English ...            '),
	(101, 'Joshua Ryan Hutcherson was born on October 12, 1992 in Union, Kentucky to Michelle Fightmaster, who worked for Delta Air Lines, and Chris Hutcherson, an EPA analyst. He has one younger brother, Connor Hutcherson. From the age of four, Josh knew that he wanted to be an actor. In order to pursue his goal, Josh and his family moved to Los Angeles ...            '),
	(102, 'Blond, blue-eyed, tall and handsome Dutch actor Rutger Hauer enjoyed an international reputation for playing everything from romantic leads to action heroes to sinister villains. Hauer was born in Breukelen, a Dutch town and former municipality in the province of Utrecht. He was the son of Teunke (Mellema) and Arend Hauer, actors who operated an ...            '),
	(103, 'Graham Verchere was born on February 4, 2002 in Vancouver, British Columbia, Canada. He is an actor, known for Stargirl ) The Good Doctor )and Summer of 84 )            '),
	(104, 'Ed Helms was born on January 24, 1974 in Atlanta, Georgia, USA as Edward Parker Helms. He is an actor, known for The Hangover ) The Office )and Vacation )            '),
	(105, 'Rachel Anne McAdams was born on November 17, 1978 in London, Ontario, Canada, to Sandra Kay (Gale), a nurse, and Lance Frederick McAdams, a truck driver and furniture mover. She is of English, Welsh, Irish, and Scottish descent. Rachel became involved with acting as a teenager and by the age of 13 was performing in Shakespearean productions in ...            '),
	(106, 'Curly haired and with a fast-talking voice, Jesse Eisenberg is a movie actor, known for his Academy Award nominated role as Mark Zuckerberg in the 2010 film The Social Network. He has also starred in the films The Squid and the Whale, Adventureland, The Education of Charlie Banks, 30 Minutes or Less, Now You See Me and Zombieland. Additionally, he...            '),
	(107, 'Wil Traval was born on July 9, 1980 in Victoria, Australia as William Traval. He is an actor, known for All Saints ) Arrow )and Jessica Jones )            '),
	(108, 'Michael Corbett Shannon was born and raised in Lexington, Kentucky, the son of Geraldine Hine, a lawyer, and Donald Sutherlin Shannon, an accounting professor at DePaul University. His grandfather was entomologist Raymond Corbett Shannon. Shannon began his professional stage career in Chicago. His first acting role was in "Winterset" at the ...            '),
	(109, 'Kristen Carroll Wiig was born on August 22, 1973 in Canandaigua, New York, to Laurie J. (Johnston), an artist, and Jon J. Wiig, a lake marina manager. She is of Norwegian (from her paternal grandfather), Irish, English, and Scottish descent. The family moved to Lancaster, Pennsylvania, before settling in Rochester, New York. When Wiig was 9 years ...            '),
	(110, 'Ginnifer Goodwin was born Jennifer Michelle Goodwin on May 22, 1978, in Memphis, Tennessee, to Linda (Kantor), who worked at FedEx, and Tim Goodwin, who had a recording studio. Bright and talented, Ginnifer carried her love for theater and acting through her high school years. She graduated from Lausanne Collegiate School in 1996 and spent a year ...            '),
	(111, 'Maya Rudolph was born on July 27, 1972 in Gainesville, Florida, to Richard Rudolph, a music producer, and soul singer Minnie Riperton. Her mother was African-American and her father is Ashkenazi Jewish (from a family from Lithuania, Russia, Germany, and Hungary). In 1973, Maya, her parents, and her older brother, Marc Rudolph, moved to California ...            '),
	(112, 'Peter Coyote was born in Manhattan, New York City, New York, USA as Robert Peter Cohon to Ruth (Fidler) and Morris Cohon, an investment banker. He is an actor, known for Bitter Moon ) Sphere )and Patch Adams ) Coyote was previously married to Stefanie Pleet and Marilyn McCann.            '),
	(113, 'Kasi Lemmons was born on February 24, 1961 in St. Louis, Missouri, USA as Karen Lemmons. She is an actress, known for The Silence of the Lambs ) Candyman )and Harriet ) She has been married to Vondie Curtis-Hall since 1995. They have two children.            '),
	(114, 'Paul Stephen Rudd was born in Passaic, New Jersey. His parents, Michael and Gloria, both from Jewish families, were born in the London area, U.K. He has one sister, who is three years younger than he is. Paul traveled with his family during his early years, because of his father s airline job at TWA. His family eventually settled in Overland Park,...            '),
	(115, 'Acting chameleon Sir Tom Courtenay, along with Sir Alan Bates and Albert Finney, became a front-runner in an up-and-coming company of rebel upstarts who created quite a stir in British "kitchen sink" cinema during the early  60s. An undying love for the theatre, however, had Courtenay channeling a different course from the aforementioned greats ...            '),
	(116, 'John Witherspoon was born on January 27, 1942 in Detroit, Michigan, USA as John Weatherspoon. He was an actor, known for Friday ) Next Friday )and Little Nicky ) He was married to Angela Robinson Witherspoon. He died on October 29, 2019 in Sherman Oaks, California, USA.            '),
	(117, 'Henry Thomas was born on September 9, 1971 in San Antonio, Texas, USA as Henry Jackson Thomas Jr. He is an actor and producer, known for E.T. the Extra-Terrestrial ) 11:14 )and Legends of the Fall ) He was previously married to Marie Zielcke and Kelly Hill.            '),
	(118, 'Randy Couture is a collegiate wrestler and fighter turned actor from Everett, Washington. He served as a four time US Olympic wrestling team alternate as a soldier in the U.S. Army, and is also a 6 time world heavyweight and light heavyweight UFC champion and Hall of Famer. He is a graduate of Oklahoma State University with a bachelor s degree in ...            '),
	(119, 'Stephen Rea was born in Belfast, Northern Ireland. He attended Belfast High School and the Queen s University, where he studied English. He later trained at the Abbey Theatre School in Dublin. In 1970s, he acted in the Focus Company in Dublin with the talented Gabriel Byrne and Colm Meaney. After several stage, television and film appearances, he ...            '),
	(120, 'Jodie Foster started her career at the age of two. For four years she made commercials and finally gave her debut as an actress in the TV series Mayberry R.F.D. ) In 1975 Jodie was offered the role of prostitute Iris Steensma in the movie Taxi Driver ) This role, for which she received an Academy Award nomination in the "Best ...            '),
	(121, 'Born in London, England, Hayley Elizabeth Atwell has dual citizenship of the United Kingdom and the United States. An only child, Hayley was named after actress Hayley Mills. Her parents, Alison (Cain) and Grant Atwell, both motivational speakers, met at a London workshop of Dale Carnegie s self-help bible "How to Win Friends and Influence People"...            '),
	(122, 'Hugh Michael Jackman is an Australian actor, singer, multi-instrumentalist, dancer and producer. Jackman has won international recognition for his roles in major films, notably as superhero, period, and romance characters. He is best known for his long-running role as Wolverine in the X-Men film series, as well as for his lead roles in the ...            '),
	(123, 'Emily Olivia Leah Blunt is a British actress known for her roles in The Devil Wears Prada ) The Young Victoria ) Edge of Tomorrow ) and The Girl on the Train ) among many others. Blunt was born on February 23, 1983, in Roehampton, South West London, England, the second of four children in the family of Joanna Mackie, a ...            '),
	(124, 'Sebastian Stan was born on August 13, 1982, in Constanta, Romania. He moved with his mother to Vienna, Austria, when he was eight, and then to New York when he was twelve. Stan studied at Rutgers Mason Gross School of the Arts and spent a year at Shakespeare s Globe Theatre in London. When he went back to New York he started working in some ...            '),
	(125, 'Jason Bateman is an American film and television actor, known for his role as Michael Bluth on the television sitcom Arrested Development ) as well as his role on Valerie ) He was born in Rye, New York. His father, Kent Bateman, from a Utah-based family, is a film and television director and producer, and founder of a Hollywood ...            '),
	(126, 'Laura Jeanne Reese Witherspoon was born on March 22, 1976 at Southern Baptist Hospital (now Memorial Medical Center) in New Orleans, Louisiana. She is the second child of Mary Elizabeth "Betty" (Reese) and Dr. John Draper Witherspoon, Sr. Her father was a military surgeon specializing in ear, nose and throat. Her mother was a Registered Nurse who ...            '),
	(127, 'Johnny Depp is perhaps one of the most versatile actors of his day and age in Hollywood. He was born John Christopher Depp II in Owensboro, Kentucky, on June 9, 1963, to Betty Sue (Wells), who worked as a waitress, and John Christopher Depp, a civil engineer. Depp was raised in Florida. He dropped out of school when he was 15, and fronted a series ...            '),
	(128, 'Michael Peña was born and raised in Chicago, to Nicolasa, a social worker, and Eleuterio Peña, who worked at a button factory. His parents were originally from Mexico. After graduating from high school, he went to an open casting call for the Peter Bogdanovich feature To Sir, with Love II ) and to his surprise, beat out hundreds of other ...            '),
	(129, 'Jamie Chung was born and raised in California, the daughter of Korean parents. She studied Economics at the University of California, Riverside. Chung s break came in 2004, when she was working in a sports bar. MTV held auditions for The Real World )there, she tried out, and was successful, appearing in the San Diego based fourteenth season. ...            '),
	(130, 'Dennis Quaid was born in Houston, Texas, to Juanita Bonniedale (Jordan), a real estate agent, and William Rudy Quaid, an electrician. He grew up in the Houston suburban city of Bellaire. He was raised a Baptist, and studied drama, Mandarin Chinese, and dance while a student at Bellaire High School. He continued study at the University of Houston, ...            '),
	(131, 'Tasha de Vasconcelos was born in Beira, Mozambique, with Portuguese ancestry on her father s side and British on her mother s side. Her old European background is very evident in her multilingual diversity and her capacity to interact with different cultures. Due to social unrest in Africa her family moved to Canada, where Tasha went on to study ...            '),
	(132, 'Jon Heder was born on October 26, 1977 in Fort Collins, Colorado, USA as Jonathan Joseph Heder. He is an actor and producer, known for Napoleon Dynamite ) Blades of Glory )and The Benchwarmers ) He has been married to Kirsten Heder since November 23, 2002. They have three children.            '),
	(133, 'Jamie Foxx is an American actor, singer and comedian. He won an Academy Award for Best Actor, BAFTA Award for Best Actor in a Leading Role, and Golden Globe Award for Best Actor in a Musical or Comedy, for his work in the biographical film Ray ) The same year, he was nominated for the Academy Award for Best Supporting Actor for his role in ...            '),
	(134, 'Considered by many critics to be the greatest living actress, Meryl Streep has been nominated for the Academy Award an astonishing 21 times, and has won it three times. Meryl was born Mary Louise Streep in 1949 in Summit, New Jersey, to Mary Wolf (Wilkinson), a commercial artist, and Harry William Streep, Jr., a pharmaceutical executive. Her ...            '),
	(135, 'With an almost unpronounceable surname and a thick Austrian accent, who would have ever believed that a brash, quick talking bodybuilder from a small European village would become one of Hollywood s biggest stars, marry into the prestigious Kennedy family, amass a fortune via shrewd investments and one day be the Governor of California!? The ...            '),
	(136, 'Geoffrey Roy Rush was born on July 6, 1951, in Toowoomba, Queensland, Australia, to Merle (Bischof), a department store sales assistant, and Roy Baden Rush, an accountant for the Royal Australian Air Force. His mother was of German descent and his father had English, Irish, and Scottish ancestry. He was raised in Brisbane, Queensland, after his ...            ')

	Select*
	from actorBio
 INSERT INTO Movie (id, rating, title, releasedate,	Price, genreID, noOfUsersWhorated)
Values
	(1, 6.6, '12 Strong', '2018', 500, 1, 42919),
	(
		2,
		8.6,
		'The Silence of the Lambs',
		'1991',
		500,
		10,
		1091846
	),
	(3, 8.2, 'Blade Runner', '1982', 500, 8, 609925),
	(4, 8.1, 'Logan', '2017', 500, 1, 525404),
	(
		5,
		7.4,
		'Harry Potter and the Chamber of Secrets',
		'2002',
		500,
		7,
		475434
	),
	(6, 6.1, 'Hotel Artemis', '2018', 500, 1, 22125),
	(7, 7.3, 'Ant-Man', '2015', 500, 1, 463386),
	(8, 8.1, 'Jurassic Park', '1993', 500, 8, 759065),
	(
		9,
		8.1,
		'The Grand Budapest Hotel',
		'2014',
		500,
		3,
		613004
	),
	(10, 8.6, 'Se7en', '1995', 500, 10, 1242808),
	(11, 6.4, 'Prancer', '1989', 500, 5, 3981),
	(
		12,
		6.9,
		'Captain America: The First Avenger',
		'2011',
		500,
		1,
		628004
	),
	(
		13,
		8.4,
		'Django Unchained',
		'2012',
		500,
		5,
		1171124
	),
	(14, 8.3, 'Scarface', '1983', 500, 10, 645069),
	(15, 7.2, 'The Post', '2017', 500, 5, 97227),
	(
		16,
		6.3,
		'The Family Stone',
		'2005',
		500,
		3,
		55617
	),
	(
		17,
		7.4,
		'Crazy, Stupid, Love.',
		'2011',
		500,
		3,
		428499
	),
	(
		18,
		7.4,
		'The Guernsey Literary and Potato Peel Pie Society',
		'2018',
		500,
		5,
		17047
	),
	(
		19,
		7.2,
		'Meet Joe Black',
		'1998',
		500,
		5,
		190786
	),
	(20, 8.0, 'Zootopia', '2016', 500, 3, 364240),
	(
		21,
		6.7,
		'The Lovely Bones',
		'2009',
		500,
		5,
		142301
	),
	(
		22,
		7.7,
		'The Social Network',
		'2010',
		500,
		5,
		556816
	),
	(
		23,
		8.2,
		'V for Vendetta',
		'2005',
		500,
		1,
		931340
	),
	(24, 7.8, 'Atonement', '2007', 500, 5, 222920),
	(
		25,
		6.9,
		'Napoleon Dynamite',
		'2004',
		500,
		3,
		180713
	),
	(26, 6.7, 'Summer of 84', '2018', 500, 5, 15757),
	(27, 6.3, 'The Change-Up', '2011', 500, 3, 152067),
	(28, 8.1, 'The Thing', '1982', 500, 8, 321203),
	(
		29,
		6.4,
		'The Day After Tomorrow',
		'2004',
		500,
		1,
		376469
	),
	(
		30,
		7.8,
		'Pride & Prejudice',
		'2005',
		500,
		5,
		224943
	),
	(
		31,
		7.9,
		'E.T. The Extra-Terrestrial',
		'1982',
		500,
		8,
		328478
	),
	(
		32,
		7.3,
		'American Sniper',
		'2014',
		500,
		1,
		390321
	),
	(
		33,
		7.1,
		'The Danish Girl',
		'2015',
		500,
		5,
		140017
	),
	(34, 6.8, 'Bridesmaids', '2011', 500, 3, 244933),
	(
		35,
		8.0,
		'Pirates of the Caribbean: The Curse of the Black Pearl',
		'2003',
		500,
		1,
		944065
	),
	(36, 6.1, 'Vacation', '2015', 500, 3, 85033),
	(37, 6.7, '1985', '2018', 500, 5, 323),
	(
		38,
		6.6,
		'The Hunger Games: Mockingjay - Part 2',
		'2015',
		500,
		1,
		240848
	),
	(39, 7.6, 'Apollo 13', '1995', 500, 5, 239580),
	(40, 6.4, 'Unsane', '2018', 500, 0, 26282),
	(41, 3.2, 'Antidote', '2018', 500, 1, 53),
	(
		42,
		6.3,
		'Legally Blonde',
		'2001',
		500,
		3,
		158464
	),
	(43, 8.0, 'Groundhog Day', '1993', 500, 3, 527397),
	(44, 7.4, 'Looper', '2012', 500, 1, 489775),
	(
		45,
		5.8,
		'Friday After Next',
		'2002',
		500,
		3,
		23152
	),
	(46, 6.2, 'I Kill Giants', '2017', 500, 5, 20858),
	(
		47,
		7.8,
		'Whats Eating Gilbert Grape',
		'1993',
		500,
		5,
		193508
	),
	(48, 7.2, 'True Lies', '1994', 500, 1, 215059),
	(
		49,
		6.2,
		'Johnny English',
		'2003',
		500,
		1,
		131697
	),
	(50, 7.7, 'The Machinist', '2004', 500, 5, 323261)
	insert into Movie(id, title, releasedate)
values
	
	
	(53,'Tenet', '7-17-2020') ,
	(54,'Mulan', '7-24-2020'),
	(55,'Red notice','12-06-2020')

INSERT INTO
	MovieTrailerLink
	(Movieid, trailer_link)
Values
	(1, 'https://www.youtube.com/embed/-Denciie5oA'),
	(2, 'https://www.youtube.com/embed/8xWbc_kFus4'),
	(3, 'https://www.youtube.com/embed/IbhFZihpGfY'),
	(4, 'https://www.youtube.com/embed/Div0iP65aZo'),
	(5, 'https://www.youtube.com/embed/uU-ET1FAv3Y'),
	(6, 'https://www.youtube.com/embed/JqfuKsoEEms'),
	(7, 'https://www.youtube.com/embed/xInh3VhAWs8'),
	(8, 'https://www.youtube.com/embed/QWBKEmWWL38'),
	(9, 'https://www.youtube.com/embed/1Fg5iWmQjwk'),
	(10, 'https://www.youtube.com/embed/SpKbZ_3zlb0'),
	(11, 'https://www.youtube.com/embed/LsSM-cxp_ZQ'),
	(12, 'https://www.youtube.com/embed/jX-dpQAginE'),
	(13, 'https://www.youtube.com/embed/rC8VJ9aeB_g'),
	(14, 'https://www.youtube.com/embed/7pQQHnqBa2E'),
	(15, 'https://www.youtube.com/embed/nrXlY6gzTTM'),
	(16, 'https://www.youtube.com/embed/_wM0Zn3493o'),
	(17, 'https://www.youtube.com/embed/flvz5RMRx7E'),
	(18, 'https://www.youtube.com/embed/HTDNGv61-Dk'),
	(19, 'https://www.youtube.com/embed/JdJS07wKUAw'),
	(20, 'https://www.youtube.com/embed/g9lmhBYB11U'),
	(21, 'https://www.youtube.com/embed/jvWXV-c2hWo'),
	(22, 'https://www.youtube.com/embed/rxY9fKgK5OQ'),
	(23, 'https://www.youtube.com/embed/ZR5xUl2Suew'),
	(24, 'https://www.youtube.com/embed/WZAttjca0b8'),
	(25, 'https://www.youtube.com/embed/yeeQOZQq6Fw'),
	(26, 'https://www.youtube.com/embed/6B46J7fY4PY'),
	(27, 'https://www.youtube.com/embed/43Qc70ZeMFw'),
	(28, 'https://www.youtube.com/embed/p35JDJLa9ec'),
	(29, 'https://www.youtube.com/embed/Ze8Gshk53Y8'),
	(30, 'https://www.youtube.com/embed/cTZAzVzFShw'),
	(31, 'https://www.youtube.com/embed/aiqLxSuXBzI'),
	(32, 'https://www.youtube.com/embed/cRbAXWfthtA'),
	(33, 'https://www.youtube.com/embed/WAVj7WQfMaI'),
	(34, 'https://www.youtube.com/embed/FNppLrmdyug'),
	(35, 'https://www.youtube.com/embed/naQr0uTrH_s'),
	(36, 'https://www.youtube.com/embed/YU-42pvbBdI'),
	(37, 'https://www.youtube.com/embed/ARcTHTYQyjc'),
	(38, 'https://www.youtube.com/embed/-0wdVrC4OM4'),
	(39, 'https://www.youtube.com/embed/e3ZtOS4MCkk'),
	(40, 'https://www.youtube.com/embed/u7KZrt_cHH0'),
	(41, 'https://www.youtube.com/embed/ZoKXZAbRW8U'),
	(42, 'https://www.youtube.com/embed/6mMDaDiJ0xw'),
	(43, 'https://www.youtube.com/embed/lTnl4J5y5rw'),
	(44, 'https://www.youtube.com/embed/5AXwtch744A'),
	(45, 'https://www.youtube.com/embed/ZkqPYNq6-iI'),
	(46, 'https://www.youtube.com/embed/n7Jg-eo8nBo'),
	(47, 'https://www.youtube.com/embed/wpSGFets1oM'),
	(48, 'https://www.youtube.com/embed/3B7HG8_xbDw'),
	(49, 'https://www.youtube.com/embed/JSg2tgnvtgY'),
	(50, 'https://www.youtube.com/embed/H0fuHY4U1UA'),
	(51,'https://www.youtube.com/embed/Kvmdb6vWfic'),
	(52,'https://www.youtube.com/embed/m2RebNGTqjM'),
	(53,'https://www.youtube.com/embed/LdOM0x0XDMo'),
	(54,'https://www.youtube.com/embed/KK8FHdFluOQ'),
	(55,'https://www.youtube.com/embed/v2HH5juK_Cg')

 

 INSERT INTO  MoviePlot (Movieid, plot)
Values
	(
		1,
		'12 Strong tells the story of the first Special Forces team deployed to Afghanistan after 9/11; under the leadership of a new captain, the team must work with an Afghan warlord to take down the Taliban.'
	),
	(
		2,
		'A young FBI cadet must receive the help of an incarcerated and manipulative cannibal killer to help catch another serial killer, a madman who skins his victims.'
	),
	(
		3,
		'A blade runner must pursue and terminate four replicants who stole a ship in space, and have returned to Earth to find their creator.'
	),
	(
		4,
		'In the near future, a weary Logan cares for an ailing Professor X. However, Logans attempts to hide from the world and his legacy are upended when a young mutant arrives, pursued by dark forces.'
	),
	(
		5,
		'An ancient prophecy seems to be coming true when a mysterious presence begins stalking the corridors of a school of magic and leaving its victims paralyzed.'
	),
	(
		6,
		'Set in riot-torn, near-future Los Angeles, Hotel Artemis follows the Nurse, who runs a secret, members-only emergency room for criminals.'
	),
	(
		7,
		'Armed with a super-suit with the astonishing ability to shrink in scale but increase in strength, cat burglar Scott Lang must embrace his inner hero and help his mentor, Dr. Hank Pym, plan and pull off a heist that will save the world.'
	),
	(
		8,
		'During a preview tour, a theme park suffers a major power breakdown that allows its cloned dinosaur exhibits to run amok.'
	),
	(
		9,
		'The adventures of Gustave H, a legendary concierge at a famous hotel from the fictional Republic of Zubrowka between the first and second World Wars, and Zero Moustafa, the lobby boy who becomes his most trusted friend.'
	),
	(
		10,
		'Two detectives, a rookie and a veteran, hunt a serial killer who uses the seven deadly sins as his motives.'
	),
	(
		11,
		'A farm girl nurses a wounded reindeer she believes is one of Santas, hoping to bring it back to health in time for Christmas. Her holiday spirit inspires those around her, something her disheartened father is having trouble understanding.'
	),
	(
		12,
		'Steve Rogers, a rejected military soldier transforms into Captain America after taking a dose of a "Super-Soldier serum". But being Captain America comes at a price as he attempts to take down a war monger and a terrorist organization.'
	),
	(
		13,
		'With the help of a German bounty hunter, a freed slave sets out to rescue his wife from a brutal Mississippi plantation owner.'
	),
	(
		14,
		'In Miami in 1980, a determined Cuban immigrant takes over a drug cartel and succumbs to greed.'
	),
	(
		15,
		'A cover-up that spanned four U.S. Presidents pushed the countrys first female newspaper publisher and a hard-driving editor to join an unprecedented battle between the press and the government.'
	),
	(
		16,
		'An uptight, conservative businesswoman accompanies her boyfriend to his eccentric and outgoing familys annual Christmas celebration and finds that shes a fish out of water in their free-spirited way of life.'
	),
	(
		17,
		'A middle-aged husbands life changes dramatically when his wife asks him for a divorce. He seeks to rediscover his manhood with the help of a newfound friend, Jacob, learning to pick up girls at bars.'
	),
	(
		18,
		'In the aftermath of World War II, a writer forms an unexpected bond with the residents of Guernsey Island when she decides to write a book about their experiences during the war.'
	),
	(
		19,
		'Death, who takes the form of a young man, asks a media mogul to act as a guide to teach him about life on Earth, and in the process, he falls in love with his guides daughter.'
	),
	(
		20,
		'In a city of anthropomorphic animals, a rookie bunny cop and a cynical con artist fox must work together to uncover a conspiracy.'
	),
	(
		21,
		'Centers on a young girl who has been murdered and watches over her family - and her killer - from purgatory. She must weigh her desire for vengeance against her desire for her family to heal.'
	),
	(22, 'Harvard student'),
	(
		23,
		'In a future British tyranny, a shadowy freedom fighter, known only by the alias of "V", plots to overthrow it with the help of a young woman.'
	),
	(
		24,
		'Fledgling writer Briony Tallis, as a thirteen-year-old, irrevocably changes the course of several lives when she accuses her older sisters lover of a crime he did not commit.'
	),
	(
		25,
		'A listless and alienated teenager decides to help his new friend win the class presidency in their small western high school, while he must deal with his bizarre family life back home.'
	),
	(
		26,
		'After suspecting that their police officer neighbor is a serial killer, a group of teenage friends spend their summer spying on him and gathering evidence, but as they get closer to discovering the truth, things get dangerous.'
	),
	(
		27,
		'Dave is a married man with three kids and a loving wife, and Mitch is a single man who is at the prime of his sexual life. One fateful night while Mitch and Dave are peeing in a fountain, lightning strikes and they switch bodies.'
	),
	(
		28,
		'A research team in Antarctica is hunted by a shape-shifting alien that assumes the appearance of its victims.'
	),
	(
		29,
		'Jack Hall, paleoclimatologist, must make a daring trek from Washington, D.C. to New York City, to reach his son, trapped in the cross-hairs of a sudden international storm which plunges the planet into a new Ice Age.'
	),
	(
		30,
		'Sparks fly when spirited Elizabeth Bennet meets single, rich, and proud Mr. Darcy. But Mr. Darcy reluctantly finds himself falling in love with a woman beneath his class. Can each overcome their own pride and prejudice?'
	),
	(
		31,
		'A troubled child summons the courage to help a friendly alien escape Earth and return to his home world.'
	),
	(
		32,
		'Navy S.E.A.L. sniper Chris Kyles pinpoint accuracy saves countless lives on the battlefield and turns him into a legend. Back home to his wife and kids after four tours of duty, however, Chris finds that it is the war he cant leave behind.'
	),
	(
		33,
		'A fictitious love story loosely inspired by the lives of Danish artists Lili Elbe and Gerda Wegener. Lili and Gerdas marriage and work evolve as they navigate Lilis groundbreaking journey as a transgender pioneer.'
	),
	(
		34,
		'Competition between the maid of honor and a bridesmaid, over who is the brides best friend, threatens to upend the life of an out-of-work pastry chef.'
	),
	(
		35,
		'Blacksmith Will Turner teams up with eccentric pirate "Captain" Jack Sparrow to save his love, the governors daughter, from Jacks former pirate allies, who are now undead.'
	),
	(
		36,
		'Rusty Griswold takes his own family on a road trip to "Walley World" in order to spice things up with his wife and reconnect with his sons.'
	),
	(
		37,
		'A closeted young man goes home for the holidays and struggles to reveal his dire circumstances to his conservative family.'
	),
	(
		38,
		'Katniss and a team of rebels from District 13 prepare for the final battle that will decide the future of Panem.'
	),
	(
		39,
		'NASA must devise a strategy to return Apollo 13 to Earth safely after the spacecraft undergoes massive internal damage putting the lives of the three astronauts on board in jeopardy.'
	),
	(
		40,
		'A young woman is involuntarily committed to a mental institution, where she is confronted by her greatest fear--but is it real or a product of her delusion?'
	),
	(
		41,
		'An altruistic doctor (Natali Yura) and cocky treasure hunters (Randy Couture) and (Chuck Zito) must join forces to uncover the Mayan legend of the White Witch.'
	),
	(
		42,
		'Elle Woods, a fashionable sorority queen is dumped by her boyfriend. She decides to follow him to law school, while she is there she figures out that there is more to her than just looks.'
	),
	(
		43,
		'A weatherman finds himself inexplicably living the same day over and over again.'
	),
	(
		44,
		'In 2074, when the mob wants to get rid of someone, the target is sent into the past, where a hired gun awaits - someone like Joe - who one day learns the mob wants to close the loop by sending back Joes future self for assassination.'
	),
	(
		45,
		'Craig and Day Day have finally moved out of their parents houses and into their own crib. The cousins work nights at a local mall as security guards. When their house is robbed on Christmas...'
	),
	(
		46,
		'Barbara Thorson struggles through life by escaping into a fantasy life of magic and monsters.'
	),
	(
		47,
		'After his fathers death, Gilbert has to care for his mentally-disabled brother, Arnie, and his morbidly obese mother. This situation is suddenly challenged though, when love unexpectedly walks into his life.'
	),
	(
		48,
		'A fearless, globe-trotting, terrorist-battling secret agent has his life turned upside down when he discovers his wife might be having an affair with a used car salesman while terrorists smuggle nuclear war heads into the United States.'
	),
	(
		49,
		'After a sudden attack on the MI5, Johnny English, Britains most confident yet unintelligent spy, becomes Britains only spy.'
	),
	(
		50,
		'An industrial worker who hasnt slept in a year begins to doubt his own sanity.'
	)


INSERT INTO _Cast (movie_id, actor_id)
Values
	(1, 1),
	(1, 2),
	(2, 3),
	(2, 4),
	(2, 5),
	(3, 6),
	(3, 7),
	(3, 8),
	(4, 9),
	(4, 10),
	(4, 11),
	(5, 12),
	(5, 13),
	(5, 14),
	(6, 15),
	(6, 16),
	(6, 17),
	(7, 18),
	(7, 19),
	(7, 20),
	(8, 21),
	(8, 22),
	(8, 23),
	(9, 24),
	(9, 25),
	(9, 26),
	(10, 27),
	(10, 28),
	(10, 29),
	(11, 30),
	(11, 31),
	(11, 32),
	(12, 33),
	(12, 34),
	(12, 35),
	(13, 36),
	(13, 37),
	(13, 38),
	(14, 39),
	(14, 40),
	(14, 41),
	(15, 42),
	(15, 43),
	(15, 44),
	(16, 45),
	(16, 46),
	(16, 47),
	(17, 48),
	(17, 49),
	(17, 50),
	(18, 51),
	(18, 52),
	(18, 53),
	(19, 54),
	(19, 55),
	(19, 56),
	(20, 57),
	(20, 58),
	(20, 59),
	(21, 60),
	(21, 61),
	(21, 62),
	(22, 63),
	(22, 64),
	(22, 65),
	(23, 66),
	(23, 67),
	(23, 68),
	(24, 69),
	(24, 70),
	(24, 71),
	(25, 72),
	(25, 73),
	(25, 74),
	(26, 75),
	(26, 76),
	(26, 77),
	(27, 78),
	(27, 79),
	(27, 80),
	(28, 81),
	(28, 82),
	(28, 83),
	(29, 84),
	(29, 85),
	(29, 86),
	(30, 87),
	(30, 88),
	(30, 89),
	(31, 90),
	(31, 91),
	(31, 92),
	(32, 93),
	(32, 94),
	(32, 95),
	(33, 96),
	(33, 97),
	(33, 98),
	(34, 99),
	(34, 100),
	(34, 101),
	(35, 102),
	(35, 103),
	(35, 104),
	(36, 105),
	(36, 106),
	(36, 107),
	(37, 108),
	(37, 109),
	(37, 110),
	(38, 111),
	(38, 112),
	(38, 113),
	(39, 114),
	(39, 115),
	(39, 116),
	(40, 117),
	(40, 118),
	(40, 119),
	(41, 120),
	(41, 121),
	(41, 122),
	(42, 123),
	(42, 124),
	(42, 125),
	(43, 126),
	(43, 127),
	(43, 128),
	(44, 129),
	(44, 130),
	(44, 131),
	(45, 132),
	(45, 133),
	(45, 134),
	(46, 135),
	(46, 136)

INSERT INTO Users(id, email)
Values
('SRQ7','srq77@gmail.com'),
('Hira29','hira2899@yahoo.com'),
('Warda1','warda112@gmail.com'),
('Ali7','sethi89@gmail.com'),
('hackerman','robo2019@yahoo.com'),
('potter','harry10@gmail.com'),
('faryal','fari74@hotmail.com'),
('nabeel','nabeel119@gmail.com'),
('jessiepinkman','32369@hotmail.com'),
('Alanwalker','walker99@yahoo.com')

INSERT INTO UserPassword(userEmail,[password])
Values
('srq77@gmail.com','Nihilist'),
('hira2899@yahoo.com','MrRobot'),
('warda112@gmail.com','Project123'),
('sethi89@gmail.com','Sethihunmain'),
('robo2019@yahoo.com','getsjobdone7'),
('harry10@gmail.com','MrRobot'),
('fari74@hotmail.com','Orange'),
('nabeel119@gmail.com','Flavoured'),
('32369@hotmail.com','icecream'),
('walker99@yahoo.com','milkshake')

INSERT INTO Watchlist(userEmail,movie_id)
Values
('hira2899@yahoo.com',10),
('warda112@gmail.com',2),
('nabeel119@gmail.com',4),
('nabeel119@gmail.com',6),
('walker99@yahoo.com',7)

INSERT INTO MoviesRent(userEmail,movieID,RentDate,DueDate)
Values ('srq77@gmail.com',10,'2020-01-07','2020-03-07'),
('hira2899@yahoo.com',2,'2020-01-17','2020-03-17'),
('warda112@gmail.com',5,'2020-02-11','2020-04-11'),
('warda112@gmail.com',6,'2020-03-04','2020-05-04'),
('warda112@gmail.com',2,'2020-03-22','2020-05-22')

select * from Actor
select * from Movie
select * from MovieTrailerLink
select * from MoviePlot
select * from _Cast
select * from Users
select* from UserPassword
select * from Watchlist
select * from MoviesRent
select * from Genre

go



-- view Users
go
create Procedure ViewUsers
As
Begin
Select u.id, email, password
From Users as u join UserPassword p on u.email=p.userEmail
End
go
 exec ViewUsers

--Usersignup
go

create Procedure Usersignup @userId nvarchar(100), @password nvarchar(100), @email nvarchar(100), @output int OUTPUT
As
Begin

if exists (select * From Users u join UserPassword p on u.email=p.userEmail where u.id=@userId)
Begin
set @output= -2

return
End
else if exists (select * From Users where email=@email)
Begin

set @output = 0
return
End
else
    Insert into Users values (@userId, @email)
    Insert into UserPassword values(@email, @password)

set @output= 1
End

go

declare  @out2 int
exec Usersignup 'doublecheck1', 'doublecheck1', 'doublecheck1@gmail.com', @out2 OUT
Select @out2
go

-- UserLogin
  go
create Procedure UserLogin  @email nvarchar(50), @password nvarchar(50), @output int OUTPUT
 As
 Begin

  if  not exists (select * From Users u join UserPassword p on u.email= p.userEmail where email=@email AND [password]=@password)
  Begin
 
  set @output = 0
  return
  End

  set @output = 1
 End

 go


 go
 declare  @out int
 exec UserLogin 'srq77@gmail.com', 'Nihilist', @out  out
 Select @out
 go

--view Movie
go
create Procedure displayMovie @movieID int
As
Begin
select  m.id,title, rating, g.genre_name,trailer_link,noOfUsersWhorated, plot, releasedate, Price
from Movie m join Genre g on m.genreID = g.genreid
join MovieTrailerLink as t on m.id=t.Movieid
join MoviePlot p on m.id=p.Movieid
where m.id=@movieID
select Actor.name, Actor.gender, Actor.id
from Actor join _cast on _Cast.actor_id = Actor.id  
where _cast.movie_id=@movieID
end
 

exec displayMovie 52


create procedure displayUpcoming
@movieID int
as
Begin
select *
from Movie join MovieTrailerLink on Movie.id = MovieTrailerLink.Movieid
where Movie.id = @movieID
End
go

exec dbo.displayUpcoming 51

--view Actor

create Procedure displayActorMovie @actorID int
As
Begin
select Movie.title,Movie.id
from Movie join _cast on _cast.movie_id=id  
where _cast.actor_id=@actorID
End
go

exec displayActorMovie 7
go

--add rating
create Procedure addrating @rating float, @movieID int
As
Begin
Update Movie  
set rating = ((rating*noOfUsersWhorated)+@rating )/(noOfUsersWhorated+1),
noOfUsersWhorated = noOfUsersWhorated+1
where Movie.id=@movieID
return
End
go

exec addrating '10',0
select*
from movie

select *
from Movie
where title = 'Trumbo'

-- Search movies and actors
go
create Procedure dbo.Search
@search nvarchar(100)
As
Begin
Select distinct [name] as Actors, id as ID
from Actor
where [name] like @search + '%' OR [name] like '%'+@search OR [name] like '%'+@search+'%'

Select distinct [title] as Movies, id as ID
from Movie
where [title] like @search + '%' OR [title] like '%'+@search OR [title] like '%'+@search+'%'
End

go
execute Search
@search = 'Br'

go

--recommended movies
create Procedure displayRecommended
As
Begin
select top(5) id,rating, title, trailer_link, plot, releasedate, Price, genreID
from Movie as m join MovieTrailerLink as t on m.id=t.Movieid
join MoviePlot as p on t.Movieid=p.Movieid
Order by NEWID()

End
go

execute displayRecommended
 go

 --AddToWatchList
go
alter Procedure dbo.AddToWatchList
@movieID int,
@Email nvarchar(50),
@output int OUTPUT
As
Begin

if exists (select* from Users where Users.email = @Email)
begin
if exists (select* from Movie where Movie.id = @movieID)
Begin
if  not exists (select * From Watchlist where userEmail = @Email AND  movie_id = @movieID)
begin
INSERT INTO Watchlist(movie_id,userEmail)
Values(@movieID,@Email)
set @output= 1

return
end
else
begin

set @output = 0
end

End
else
begin
set @output= 0

end
end
else
begin
set @output = 0

end
END
go

go
declare @out nvarchar(50), @out2 int
exec AddToWatchList 2, 'srq77@gmail.com', @out OUT,  @out2 OUT
Select @out, @out2

go

--ShowTopRatedMovies
alter Procedure dbo.ShowTopRatedMovies
As
Begin
Select top (10) id,title, rating
from Movie
Order by Rating desc
End


go

exec.ShowTopRatedMovies

--ShowUpcomingMovies
go
create Procedure dbo.ShowUpcomingMovies
As
Begin
Select*
from Movie
where Movie.releasedate > getDate()
End
go

execute ShowUpcomingMovies
go

--ShowTrailers
go
create Procedure dbo.ShowTrailers
As
Begin
Select trailer_link
from MovieTrailerLink
End

go
Execute ShowTrailers
go


--rent video
go
create Procedure rentVideo @email nvarchar(50), @movieID int,@output int OUTPUT
As
Begin

if exists (select * From Users where email=@email)
Begin
if exists (select * From Movie where id=@movieID)
Begin
if  not exists (select * From MoviesRent where userEmail=@email AND movieID=@movieID)
Begin
Insert into  MoviesRent values (@email, @movieID, CONVERT(VARCHAR(10), getdate(), 111),DATEADD(month,1,CONVERT(VARCHAR(10), getdate(), 111) ))

set @output = 1
return
end
else
begin

set @output = 0
end
End
else
begin

set @output = -2
end

End

End


go

declare @out int
exec rentVideo 'srq77@gmail.com', 6, @out OUT
Select @out
go

--viewActor

alter procedure dbo.viewActor
@actorID int
As
Begin

Select*
from Actor join actorBio on Actor.id = actorBio.id
where Actor.id = @actorID
exec dbo.displayActorMovie @actorID

End

exec dbo.viewActor 7

alter procedure dbo.ShowWatchlist
@userEmail nvarchar(50) 
as
Begin
Select movie_id as id, title
from Users join Watchlist on Users.email = Watchlist.userEmail join Movie on Watchlist.movie_id = Movie.id
where Users.email = @userEmail
End

exec dbo.ShowWatchlist 'chack@gmail.com' 

alter procedure dbo.ShowRentedMovies
@userEmail nvarchar(50)
As
Begin
Select movieID as id,title
from Users join MoviesRent on Users.email = MoviesRent.userEmail join Movie on MoviesRent.movieID = Movie.id
where Users.email = @userEmail
End

exec dbo.ShowRentedMovies 'chack@gmail.com' 